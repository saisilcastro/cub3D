#include <cub3d.h>

#define EPSILON 0.001f // Small value to adjust for floating-point inaccuracies

// Function to cast a vertical ray and return the distance to the wall and the y-coordinate of the intersection point
t_vf2d ray_vertical(t_object *obj, t_vf2d *direction, float angle) {
    t_vf2d step, next, delta;
    float dist;
    t_map *level = cub_get()->level;
    int map_x, map_y;

    // Initialize step direction
    step.x = (direction->x < 0) ? -1 : 1;
    step.y = step.x * tanf(angle);

    // Calculate next horizontal and vertical intersection points
    next.x = (int)(obj->pos->x / level->block->x) * level->block->x;
    next.y = obj->pos->y + (next.x - obj->pos->x) * tanf(angle);
    next.y += (direction->y < 0) ? -EPSILON : EPSILON; // Adjust for floating point inaccuracies

    // Calculate delta x and y
    delta.x = fabsf(level->block->x / cosf(angle));
    delta.y = fabsf(level->block->y / sinf(angle));

    // Adjust delta signs based on step direction
    delta.x *= (step.x < 0) ? -1 : 1;
    delta.y *= (step.y < 0) ? -1 : 1;

    // Initialize distance
    dist = 0;

    // Perform raycasting
    while (dist < cub_get()->gear->size->x) {
        // Calculate the cell coordinates on the map
        map_x = (int)(next.x / level->block->x);
        map_y = (int)(next.y / level->block->y);

        // Check if the cell coordinates are within the map bounds
        if (map_x >= 0 && map_x < level->size->x && map_y >= 0 && map_y < level->size->y) {
            // Check for wall collision
            if (level->map[map_y][map_x] == '1') {
                // Calculate distance to wall
                float xdist = next.x - obj->pos->x;
                float ydist = next.y - obj->pos->y;
                dist = sqrtf(xdist * xdist + ydist * ydist) * cosf(angle - obj->angle);
                break;
            }
        } else {
            // If the cell coordinates are out of bounds, break the loop
            break;
        }

        // Move to the next intersection point
        dist += (delta.x < delta.y) ? delta.x : delta.y; // Choose the smaller delta
        next.x += (dist < cub_get()->gear->size->x) ? delta.x : 0;
        next.y += (dist < cub_get()->gear->size->x) ? delta.y : 0;

        // Check if the next intersection point is within the map bounds
        map_x = (int)(next.x / level->block->x);
        map_y = (int)(next.y / level->block->y);
        if (map_x < 0 || map_x >= level->size->x || map_y < 0 || map_y >= level->size->y) {
            // If out of bounds, break the loop
            break;
        }
    }

    // Return the distance to the wall and the y-coordinate of the intersection point
    return vf2d_start(dist, next.y - obj->pos->y);
}

// Function to draw the rays on the screen
void draw_rays(t_object *obj, t_image *img) {
    t_pixel ray_color = {255, 0, 255, 255}; // Ray color (red)
    t_map *level = cub_get()->level;
    float fov = 60; // Field of view in degrees
    int num_rays = 120;//cub_get()->gear->size->x; // Number of rays equals the width of the screen

    // Convert field of view from degrees to radians
    float fov_radians = fov * (M_PI / 180.0);

    // Calculate the angle increment per ray in radians
    float angle_increment = fov_radians / num_rays;

    // Start angle for the first ray in radians
    float start_angle = deg_to_rad(obj->angle) - fov_radians / 2;

    // Perform raycasting for each vertical line of the screen
    for (int x = 0; x < num_rays; x++) {
        // Calculate the angle for this ray in radians
        float ray_angle = start_angle + angle_increment * x;

        // Calculate ray direction based on the angle
        t_vf2d ray_direction;
        ray_direction.x = cosf(ray_angle);
        ray_direction.y = -sinf(ray_angle);

        // Initialize ray length
        float ray_length = 0;

        // Perform raycasting to detect walls
        while (ray_length < cub_get()->gear->size->x) {
            // Calculate the next point along the ray
            float next_x = obj->pos->x + ray_direction.x * ray_length;
            float next_y = obj->pos->y + ray_direction.y * ray_length;

            // Calculate the cell coordinates on the map
            int map_x = (int)(next_x / level->block->x);
            int map_y = (int)(next_y / level->block->y);

            // Check if the cell coordinates are within the map bounds
            if (map_x >= 0 && map_x < level->size->x && map_y >= 0 && map_y < level->size->y) {
                // Check for wall collision
                if (level->map[map_y][map_x] == '1') {
                    // Adjust ray length to end at the wall
                    ray_length = fmin(ray_length, fabsf((next_x - obj->pos->x) / cosf(ray_angle)));
                    break;
                }
            } else {
                // If the cell coordinates are out of bounds, break the loop
                break;
            }

            // Increment ray length
            ray_length += 0.1f; // Adjust this step size as needed for accuracy
        }

        // Draw the ray
        float scale = cub_get()->gear->size->y / (2 * ray_length * tanf(fov_radians / 2));
        float wall_height = scale * cub_get()->gear->size->y;
        mlx_draw_line(img, vf2d_start(obj->pos->x, obj->pos->y),
                      vf2d_start(obj->pos->x + ray_direction.x * ray_length, obj->pos->y + ray_direction.y * ray_length),
                      pixel_to_int(&ray_color));
    }
}

void draw_rectangle(t_image *img, int x, int y, int width, int height, t_pixel *color) {
    // Draw a filled rectangle on the image
    for (int dy = 0; dy < height; dy++) {
        for (int dx = 0; dx < width; dx++) {
            draw_pixel(img, x + dx, y + dy, *((int *)color));
        }
    }
}

void ray_cast(t_object *obj, t_image *img) {
    t_map *level = cub_get()->level;
    float fov = 60; // Field of view in degrees
    float fov_radians = deg_to_rad(fov);
    float player_angle_radians = deg_to_rad(obj->angle);
    int screen_width = cub_get()->gear->size->x;
    int screen_height = cub_get()->gear->size->y;

    if (cub_get()->map_show)
        draw_rays(obj, img);

    // for (int x = 0; x < screen_width; x++) {
    //     float camera_x = 2 * x / (float)screen_width - 1;
    //     float ray_angle = player_angle_radians + atan2f(obj->route->y, obj->route->x) - fov_radians / 2 + camera_x * fov_radians / screen_width;
    //     t_vf2d ray_direction = {cosf(ray_angle), sinf(ray_angle)};
    //     t_vf2d ray_distance = ray_vertical(obj, &ray_direction, ray_angle);
    //     float corrected_distance = fabs(ray_distance.x) * cosf(ray_angle - player_angle_radians);
    //     int wall_height = (int)(screen_height / corrected_distance);
    //     int wall_top = (screen_height - wall_height) / 2;
    //     int wall_bottom = wall_top + wall_height;

    //     for (int y = 0; y < level->size->y; y++) {
    //         for (int z = 0; z < level->size->x; z++) {
    //             if (level->map[y][z] == '1') {
    //                 int wall_x = z * level->block->x;
    //                 int wall_width = level->block->x;
    //                 if (wall_x >= 0 && wall_x < screen_width) {
    //                     draw_rectangle(img, wall_x, wall_top, wall_width, wall_height, &(t_pixel){255, 0, 0, 255});
    //                 }
    //             }
    //         }
    //     }
    // }
}