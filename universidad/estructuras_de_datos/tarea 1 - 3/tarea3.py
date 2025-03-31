"""
Nombre: Daniel Alejandro Posada Noguera
Codigo: 8980619
Fecha: 20/02/2024
"""


#Punto 1
def getLowest( l, v ):              
    lst = List()                   
    n = l.size()                 
    i = 0              
    while i < n:                    
        e = l.at( i )               
        if e < v:                   
            lst.push_back( e )      
        i+=1                        
    return lst


#Punto 2
def insertSortedList( l, v ):                
    flag = False                
    n = l.size()                         
    i = 0
    while not flag and i < n:               
        if v > l.at( i ):      
            flag = True
            l.insert( v, i )
        i+= 1
    if not flag:
        l.pushback( v )


#Punto 3                             
def listDifference( l1, l2 ):        
    i = 0                            
    while i < l2.size():             
        e = l2.at( i )               
        j = 0                        
        while j < l1.size():             
            if e == l1.at( j ):      
                l1.remove( j )       
            else:
                j+=1                 
        i+=1                         


#Punto 4
def moveElements( l, k ):            
    i, n = 0, l.size()               
    aux = List()                     
    while i < n:
        aux.push( 0 )
        i+=1
    for i in range( n ):
        aux.set( (i + k) % n, l.at( i ) )
    for i in range( n ):
        l.set( i, aux.at( i ) )
        

#Punto 5
def getSecondLargest( p ):                 
    aux = Stack()                       
    ans = p.peek()                       
    max_v = p.peek()                     
    times = 0                              
    while not p.empty():                     
        e = p.peek()                    
        aux.push( e )                      
        if e > max_v:             
            max_v = e                                          
        p.pop()                          

    while not aux.empty():        
        e = aux.peek()
        if e == max_v:         
            times +=1                 
        if times >=2:             
            ans = max_v     
        elif ans < e < max_v:   
            ans = e            
        p.push( e )            
        aux.pop()              

    return ans


#Punto 6
def separateStack( p ):                
    auxPares = Stack()             
    auxImpares = Stack()
    ans = Stack()
    while not p.empty():               
        e = p.peek()                   
        if e % 2 == 0:                 
            auxPares.push( e )        
        else:                         
            auxImpares.push( e )       
        p.pop()

    while not auxImpares.empty():      
        p.push( auxImpares.peek() )    
        auxImpares.pop()

    while not auxPares.empty():        
        ans.push( auxPares.peek() )    
        auxPares.pop()

    return ans


#Punto 7
def insertSortedQueue( q, v ):     
    flag = False 
    i, n = 0, q.size()              
    while i < n:                     
        e = q.front()                
        if v < e and not flag:      
            q.push( v )              
            flag = True             
        q.push( e )                  
        q.pop()                
        i+=1
    if not flag:
        q.push( v )


#Punto 8
def getReversedQueue( q ):
    ans = Queue()
    auxCola = Queue()
    auxPila = Stack()
    while not q.empty():
        e = q.front()
        auxPila.push( e )
        auxCola.push( e )
        q.pop()
    while not auxPila.empty(): 
        ans.push( auxPila.peek() )
        q.push( auxCola.front() )
        auxCola.pop()
        auxPila.pop()

    return ans

