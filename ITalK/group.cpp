#include "group.h"

Group::Group()
{
}

QString Group::getId() {
    return id;
}

QString Group::getTitre() {
    if (titre == NULL) {
        return "";
    } else {
        return titre;
    }
}
