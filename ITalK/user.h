#ifndef USER_H
#define USER_H

class User
{
private:
    String nom;

    String prenom;

    Group group;

    String pole; // ex: pôle info, Preco Team, ...

    String description; // ex: Stagiaire, DGA, ...

    String image; // url vers avatar;

    String ip; // ip de l'utilisateur

    String port; // port pour connection distante

public:
    User();

    void serialize();
};

#endif // USER_H
