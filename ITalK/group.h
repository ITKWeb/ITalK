#ifndef GROUP_H
#define GROUP_H

class Group
{
private:
    String id; // unique identifiant

    String titre; // optionel, nom du group pour le retrouver sur la page de sélection

    Set<User> users; // ensemble des personnes du groupe

public:
    Group();

    String getId();

    String getTitre();
};

#endif // GROUP_H
