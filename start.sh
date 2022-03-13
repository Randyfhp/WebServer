nginx -s reload
kill -9 `pidof $1`
/usr/local/spawn-fcgi/bin/spawn-fcgi -a 127.0.0.1 -p 9000 $1
