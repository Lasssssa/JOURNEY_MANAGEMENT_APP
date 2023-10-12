trajets=[[1,2],[2,4],[4,5],[1,3],[3,5],[5,1],[1,4],[3,2],[3,1],[2,5],[1,5]]
#on cree un graphe d'adjacence
g=dict()
for element in trajets:
    if element[0] not in g:
        g[element[0]]=[]
        g[element[0]].append(element[1])
    else:
        g[element[0]].append(element[1])

for c in g.keys():
    print(c,g[c],"\n")
#cette fonction va être appliquée chaque fois q'un depart estrencontré
def DFS(sommet,arrivee,g):
    a_explorer=[sommet]
    deja_vu=[]
    chemin={}
    chemin[sommet]=[sommet]
    while len(a_explorer)!=0:
        v=a_explorer.pop(-1)
        if v not in deja_vu:
            deja_vu.append(v)
            if v in g:
                for adj in g[v]:
                    if adj not in deja_vu:#il faut séparer ces deux éléments
                        a_explorer.append(adj)#il faut mettre à jour le chemin mais il ne faut pas le considéré comme exploré
                        chemin[adj]=chemin[v]+[adj]
            

    chemins=[]
    for element in chemin.keys():
        if chemin[element][-1]==arrivee:
            chemins.append(chemin[element])
                
        
    return chemins


def calcul_chemin_BFS(adjacents, depart, arrivee):
    rendre=[]
    a_explorer = [depart]
    #╚liste des sommets à explorer initiée avec l'element de depart
    deja_collectes = [depart]
    #ensemble des sommets deja explorer permet de trouver des boucles on veut retrouver un
    #seul chemin
    chemins = {depart: [depart]}
    while len(a_explorer) != 0:
        courant = a_explorer.pop(0)
#        if courant == arrivee:
#            return(chemins[arrivee])

        if courant in adjacents:

            for sommet in adjacents[courant]:
                #if sommet not in deja_collectes:
                    if sommet not in chemins[courant]: #si le sommet n'est pas à priori dans le trajet 
                        a_explorer.append(sommet)
                        deja_collectes.append(sommet)
                        chemins[sommet]=chemins[courant]+[sommet] #dans le dictionnaires les paths les plus courts sont 

                        if sommet==arrivee:
                            rendre.append(chemins[courant]+[sommet])
                        



    return rendre

def calcul_chemin_BFS2(adjacents, depart, arrivee):
    rendre=[]
    a_explorer = [depart]
    #╚liste des sommets à explorer initiée avec l'element de depart
    deja_collectes = [depart]
    #ensemble des sommets deja explorer permet de trouver des boucles on veut retrouver un
    #seul chemin
    chemins=[[depart]]
    longueur=len(chemins)
    indice_courant=0
    while len(a_explorer) != 0:
        courant = a_explorer.pop(0)
#        if courant == arrivee:
#            return(chemins[arrivee])

        if courant in adjacents:
                #if sommet not in deja_collectes:
                for i in range(indice_courant,longueur):
                    if chemins[i][-1] in adjacents:
                        for sommet in adjacents[chemins[i][-1]]:
                            if sommet not in chemins[i]: #si le sommet n'est pas à priori dans le trajet 
                                a_explorer.append(sommet)
                                #deja_collectes.append(sommet)
                                chemins.append(chemins[i]+[sommet]) #dans le dictionnaires les paths les plus courts sont 

                                if sommet==arrivee:
                                    if chemins[i]+[sommet] not in rendre:
                                        rendre.append(chemins[i]+[sommet])
        indice_courant=indice_courant+longueur-1
        longueur=len(chemins)
                        



    return rendre
print(calcul_chemin_BFS2(g,1,5))

def fon2(adjacents,deb,longueur,fin): 
    """
    

    Parameters
    ----------
    adjacents : dictionnaire
        DESCRIPTION.
    deb : string
        DESCRIPTION.
    longueur : integer
        DESCRIPTION.
    fin : string
        DESCRIPTION.

    Returns
    -------
    liste_finale : la liste des chemins entre deux éléments ayant une longueur minimale
                    qui est celle trouvée avec le code bfs
    TYPE
        DESCRIPTION.

    """
  #on est bien conscient qu'on aurait pu faire autrement
  #en ne retenant que les listes pertinentes dès leur ajout au lieu de procéder 
  #à un éventuel tri or on n'a pas eu le temps 
    if deb in adjacents:
        
        l0=adjacents[deb]
        l1=[]
        l1.append(l0)
        a=0
        j=0
        while a!=longueur:#sans 1 
            
            if j==0:
                for i in range(len(l1[0])):

                    l=[deb]
                    l.append(l1[0][i])
                    l1.append(l)
        
            else:
                debut=l1[-1]

                long=len(debut)
               
                for i in l1:
                    if i !=l1[0] and len(i)>long:#il faut que ça diffère du premier element 
                        long=len(i)
                #permet de trouver la longueur de la liste la plus grande soit long 
                nouvelle_liste=[]
                for i in l1:
                    if len(i)==long:
                        nouvelle_liste.append(i)
                #maintenant on a les listes ayant une longueur maximale 
                #dans cette sous partie
     
                for element in nouvelle_liste:
                    deb_suiv=element[-1]
                    if deb_suiv in adjacents:
                        arc_nouveau=adjacents[deb_suiv]
                        for espece in arc_nouveau:
                            #if espece not in element and espece in adjacents:
                            if espece in adjacents:
                                liste1=element.copy()
                                liste1.append(espece)
                                l1.append(liste1)
            
                        
            j+=1#à ne pas effacer

            #a est la longueur maximale obtenue on écrase les listes ayant une longueur ingférieure 
            #à cette longueur
            for i in l1:
                if i !=l1[0] and len(i)>a:
                    a=len(i)
        liste1=l1.copy()
        liste1.pop(0)#on enleve la liste d'adjacents pour ne garder que la liste de demi-chemins        
        liste1=trie(l1, fin)

        return liste1 #permet de retenir les listes qui finissent par les éléments qui nous intéressent
    else:
        return None
   