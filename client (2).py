import socket
import time
from tkinter import *
import threading
from tkinter import messagebox
from tkinter.messagebox import showerror,askretrycancel
from datetime import datetime
e=None
root=None
s=None


def viewhistory(*args):
    global f
    top=Tk()
    top.title(" YOUR CHATTING HISTORY")
    top.geometry("500x500+5+5")
    f=open("C:\\Users\\Gopal singh\\Desktop\\sublime py files\\ch.txt",'r')
    text=Text(top,font=("century schoolbook",10),wrap=WORD,padx=2,pady=2,bd=2)#,width=500,height=500)
    
    scroll=Scrollbar(top,command=text.yview)
    text.configure(yscrollcommand=scroll.set)
    text.pack(side=LEFT,fill=BOTH,expand=True)
    scroll.pack(side=RIGHT,fill=Y)
    text.delete(0.0,END)
    text.insert(0.0,f.read())
    top.mainloop()


def clearhistory(*args):

    answer=messagebox.askyesnocancel(" Delete History  ","Are you sure you want to permanently clear your chat history?")
    if answer==True:
        f=open("C:\\Users\\Gopal singh\\Desktop\\sublime py files\\ch.txt",'w')
        f.truncate(0)
    else:
        pass

def sr():
    global s
    host="192.168.43.254"#"192.168.43.101"#"192.168.43.254"# "192.168.43.254"# "192.168.1.3"
    port=9999

    s=socket.socket()

    s.connect((host,port))

    while True:
        if (s.recv(1024)).decode("utf-8"):
            server_response=s.recv(1024)
            server_response=server_response.decode("utf-8")
            gunc(server_response)
            print("\n")
            print("server:"+server_response,end='')
            print("\n")
        else:
            pass


def func(msg):
    global root,x,lst
    if x<8:
        f=open("C:\\Users\\Gopal singh\\Desktop\\sublime py files\\ch.txt",'r+')
        f.read()
        
        mess=Message(root,text=msg,bg='lightblue',justify='right',pady=5,padx=5,relief=GROOVE,anchor=E,aspect=1200)
        mess.config(font=("Century Schoolbook",15))
        mess.pack(fill=X)
        lst.insert(x,mess)
        f.write("\nyou:     ")
        f.write(msg)
      #  f.write("\n")
        f.close()
        x+=1
    else:
        for i in range(0,8):
            lst[i].destroy()
        x=0
        func(msg)



lst=[]
x=0

def gunc(msg):
    global root,x,lst
    if x<8:

        f=open("C:\\Users\\Gopal singh\\Desktop\\sublime py files\\ch.txt",'r+')
        f.read()

        mess=Message(root,text=msg,bg='lightgrey',justify='right',pady=5,padx=5,relief=GROOVE,anchor=W,aspect=1200)
        mess.config(font=("Century Schoolbook",15))
        mess.pack(fill=X)
        lst.insert(x,mess)
        f.write("\nserver:  ")
        f.write(msg)
     #   f.write("\n")
        f.close()
        x+=1
    else:
        for i in range(0,8):
            lst[i].destroy()
        x=0
        gunc(msg)

def main():
    global e,root
    root=Tk()
    root.geometry("600x600+2+2")
    root.resizable(0,0)
    root.title('client')

    

    bkgt= PhotoImage(file=r"C:\Users\Gopal singh\Desktop\sublime py files\bkg1.gif")
    bkg=bkgt.subsample(2,2)

    b=Label(root,image=bkg)
    b.place(x=0,y=0)

    photo = PhotoImage(file=r"C:\Users\Gopal singh\Desktop\sublime py files\download1gif.gif")
    pimg=photo.subsample(6,7)

    #thread2()
    button = Button(root,image=pimg ,command=thread) 
    button.pack(side=RIGHT,anchor=SE) 

    e=Entry(root,width=60,font=("Century Schoolbook",15))
    e.pack(side=BOTTOM,anchor=SW,ipady=10,ipadx=4)
    e.bind("<Control-h>",viewhistory)
    e.bind("<Control-H>",clearhistory)

    menubar=Menu(root)
    historymenu=Menu(menubar,tearoff=0)
    historymenu.add_command(label="View",command=viewhistory)
    historymenu.add_command(label="Clear",command=clearhistory)

    menubar.add_cascade(label='Chat History',menu=historymenu)
    root.config(menu=menubar)
    f=open("C:\\Users\\Gopal singh\\Desktop\\sublime py files\\ch.txt",'r+')
    f.read()
    x=str(datetime.now())
    print(x)
    f.write("\n\n\t\t--------")
    f.write(x)
    f.write("--------\n\n")
    f.close()


    e.bind("<Return>",client)
    thread2()
    ter=threading.Thread(target=root.mainloop())
    ter.daemon=True
    ter.start()



###3
def client(*args):
   

    #while True:
    global e,s,root
    msg=e.get()
    if sys.getsizeof(msg)>25:
        try:
           
            e.delete(0,END)#input("you:")
            s.send(str.encode(msg))
            func(msg)
            time.sleep(0.1)
            s.send(str.encode(msg))
        except:
            ans=showerror("OOPS!","server is not connected!")
            if ans=="ok":
                root.quit()

#client()

def thread2():
    t2=threading.Thread(target=sr)
    t2.daemon=True
    t2.start()
    #thread2()


def thread():
   # thread2()
    t=threading.Thread(target=client)
   # thread2()
    t.daemon=True
    t.start()
main()