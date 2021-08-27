import socket
import threading
import time
import sys
from queue import Queue
from datetime import datetime



NUMBER_OF_THREADS = 3
JOB_NUMBER = [1, 2,3]
queue = Queue()

addresses_connections = []
flag = True # Node isn't recover yet (reset)


# Create a Socket ( connect two computers)



host = '192.168.56.1' #socket.gethostbyname(socket.gethostname())
port = 9992
print("My IP address "+"| " +host + " |" +" PORT  | " + str(port) + " |")
s=socket.socket(socket.AF_INET,socket.SOCK_STREAM )
s.bind((host, port))
    
# Establish connection with a client (socket must be listening)

def socket_accept():

    print("A\n")
    s.listen(5)
    
    print("Waiting for connection....")

    while True:    
        print("B\n")
        conn, address = s.accept()

        s.setblocking(1)  # prevents timeout

        addresses_connections.append([address,conn])

        print("C\n")
        print("\nNEW CONNECTION:- {} connected.".format(address))

s1=socket.socket(socket.AF_INET,socket.SOCK_STREAM)

def socket_connect():
    print("a\n")
    while True:
        #print("b\n")
        Host= "192.168.56.7"
        Port = 9993      

        try:
            s1.connect((Host,Port))
            print("Connected with server !")
            print("c\n")
            break

        except:
            continue
        print("d\n")

    #Establish connection with server


"""def receive():

    global flag

    
    while True:

        if len(addresses_connections) > 0:

            host_conn = addresses_connections[-1][1]

            signal = False

# file 1 receiveing -------------------
            try:

                recovery_file = host_conn.recv(1024).decode("utf-8")
                #time.sleep(5)

                with open("recovery.jpg","wb") as file1:
                    while True:
                        data = host_conn.recv(1024)
                        if not data:
                            break
                        file1.write(data)
                    file1.close()    
                print("file 1  received succesfully")
                flag = True
                
                current_time = (datetime.now().strftime(' %H:%M:%S.%f'))
                print(current_time)
                forward_recovery_file(recovery_file)
            except:
                continue    

            break

        else:
            continue    """


def Receive_recovery_file():

    print("Aa\n")
    global flag

    count1 = 0
    while flag:
        count1+=1
        print("Bb\n")
        check = True
        count = 0
        while check:
            count+=1
            print("Cc\n")
            for add_conn in addresses_connections:
                conn = add_conn[1]
                try:
                    msg = conn.recv(1024).decode("utf-8")
                    print("1\n")
                    if msg =='Client':
                        with open("recovery.jpg","wb") as file1:
                            while True:
                                data = conn.recv(1024)
                                if not data:
                                    break
                                file1.write(data)
                            file1.close()
                        print("2\n")    
                        print("file received succesfully")
                        flag = False    
                        check= False
                        break
                except:
                    pass
            print("Dd\n")
            try:
                msg = s1.recv(1024).decode("utf-8")
                print("1\n")
                if msg =='Server':
                    with open("recovery.jpg","wb") as file1:
                        while True:
                            data = conn.recv(1024)
                            if not data:
                                break
                            file1.write(data)
                        file1.close()
                    print("2\n")
                    print("file received succesfully")
                    flag = False
                    check= False
            except:
                pass
            print("Ee\n")
            if count==15:
                break
        print("3\n")
        if count1 == 5:
            break
        
        #forward_recovery_file()    
                      
            
        
def forward_recovery_file():
    
    # Sending signal msg before sending a file------
    for add_conn in addresses_connections:

        conn = add_conn[1]
        try:
            conn.send(str.encode("Server"))
            print("4S\n")
        except:
            pass    
    try:
        s1.send(str.encode("Client"))
        print("4C\n")
    except:
        pass   
    # Sending Whole file to each node---------
    print("5\n")
    with  open("recovery.jpg","rb") as file1:
        data = file1.read(1024)
        while data:
            for add_conn in addresses_connections:
                conn = add_conn[1]
                try:
                    conn.send(data)
                except:
                    pass    
            try:
                s1.send(data)
            except:
                pass
            data = file1.read(1024)
        file1.close()
    print("6\n")
    print("File transfer successfull to adjacent node...")     
 
# Create worker threads


        

# Do next job that is in the queue (handle connections, send file)

def work():

    while True:

        x = queue.get()

        if x == 1:
            socket_accept()

        if x == 2:
            socket_connect()  

        if x == 3:
            Receive_recovery_file()
        queue.task_done()


def create_workers():

    for _ in range(NUMBER_OF_THREADS):

        t = threading.Thread(target=work)

        t.daemon = True

        t.start()


def create_jobs():

    for x in JOB_NUMBER:

        queue.put(x)

    queue.join()





create_workers()

create_jobs()

