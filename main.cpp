#include <iostream>

void SendSms(const std::string& number, const std::string& message) {
    std::cout << "Send '" << message << "' to number " << number << std::endl;
}

void SendEmail(const std::string& email, const std::string& message) {
    std::cout << "Send '" << message << "' to e-mail "  << email << std::endl;
}

class INotifier {
public:
    virtual void Notify (const std::string& message) = 0;
};
class SmsNotifier : public INotifier {
public:
    SmsNotifier(const std::string& Number_Phone) : Number_Phone_(Number_Phone){

    };
    void Notify (const std::string& Message) override {
        SendSms(Number_Phone_,Message);
    }
private:
    const std::string Number_Phone_;
};
class EmailNotifier : public INotifier {
public:
    EmailNotifier(const std::string& Number_Phone) : Number_Phone_(Number_Phone){
    };
    void Notify (const std::string& Message) override {
        SendSms(Number_Phone_,Message);
    }
private:
    const std::string Number_Phone_;
};

void Notify(INotifier& notifier, const std::string& message) {
    notifier.Notify(message);
}
int main() {
    SmsNotifier sms{"+7-495-777-77-77"};
    EmailNotifier email{"na-derevnyu@dedushke.ru"};

    Notify(sms, "I have White belt in C++");
    Notify(email, "And want a Yellow one");
    return 0;
}