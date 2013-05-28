#ifndef MESSAGE_H
#define MESSAGE_H

class Message
{
private:
    String text;

    Group destinataires;

    User userFrom;

    Date dateTime;

public:
    Message();

    Message(Group dest, String text, User from, Date date);

    void serialize();

    Date getDate();

    User getUserFrom();

    Group getDestinataires();

    String getText();

};

#endif // MESSAGE_H
