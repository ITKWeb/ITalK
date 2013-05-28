#ifndef MESSAGE_H
#define MESSAGE_H

class Message
{
private:
    String text;

    Group destinataires;

    User userFrom;

    String dateTime;

public:
    Message();

    void serialize();

};

#endif // MESSAGE_H
