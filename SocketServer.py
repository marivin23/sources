import socket
import threading

addr_name = socket.gethostname()
addr = socket.gethostbyname(addr_name)
print(addr)

sock = socket.socket(socket.AF_INET, socket.SOCK_STREAM)
sock.bind((addr, 10000))
sock.listen(1)

connections = []

def handler(c, a):

    global connections
    
    while True:
        data = c.recv(1024)
        for connection in connections:
            connection.send(data)
        if not data:
            connections.remove(c)
            c.close()
            break
        
while True:
    c, a = sock.accept()
    conn_thread = threading.Thread(target = handler, args = (c, a))
    conn_thread.daemon = True
    conn_thread.start()
    connections.append(c)
    print(connections)
