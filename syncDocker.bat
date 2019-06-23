REM An auxilary file for syncing the source code to linux docker container and build and test.
docker exec -it 7d2a77e425ea rm -rf /usr/vopaaz/v-shell
docker cp . 7d2a77e425ea:/usr/vopaaz/v-shell
TIMEOUT /T 4
docker exec -it -w /usr/vopaaz/v-shell 7d2a77e425ea  make
