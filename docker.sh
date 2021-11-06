#!/bin/bash
set -o nounset # Treat unset variables as an error

docker pull archlinux
docker rrun -d -p 80:80 docker/archlinux
