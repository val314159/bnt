import gevent.monkey;gevent.monkey.patch_all()
import bottle

Connections = []

# do websocket
# for every connection, publish the same packet
