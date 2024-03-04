name=$1
git checkout -b $name
git checkout $name
git add .
git commit -m "cub3d"
git push --set-upstream origin $name
