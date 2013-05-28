#include "group.h"

Group::Group()
{
}

String Group::getId() {
    return id;
}

String Group::getTitre() {
    if (titre == null) {
        return "";
    } else {
        return titre;
    }
}
