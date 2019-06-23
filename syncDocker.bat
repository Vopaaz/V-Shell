docker exec -it 7d2a77e425ea rm -rf /usr/vopaaz/min-shell
docker cp . 7d2a77e425ea:/usr/vopaaz/min-shell
TIMEOUT /T 4
docker exec -it -w /usr/vopaaz/min-shell 7d2a77e425ea  make
