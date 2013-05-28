#ifndef USER_H
#define USER_H

#include <QString>

class User
{
private:
    QString nom;

    QString prenom;

    QString pole; // ex: pôle info, Preco Team, ...

    QString description; // ex: Stagiaire, DGA, ...

    QString image; // url vers avatar;

    QString ip; // ip de l'utilisateur

    QString port; // port pour connection distante

public:
    User();

    void serialize();
};

#endif // USER_H
