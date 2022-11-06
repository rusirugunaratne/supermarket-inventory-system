#include <conio.h>
#include <math.h>
#include <string.h>

#include <fstream>
#include <iomanip>
#include <iostream>
using namespace std;
void main_menu();
ifstream fin;
ofstream fout;
fstream file;
int i;

template <typename T>
void printElement(T t) {
    cout << t << "\t\t";
}

// Stock stock;

void print_dash() {
    cout << "\n//////////////////////////////////////////////////////\n";
}

//////////////////////////////////////////////////
//////////////////////////////////////////////////
//////////////////////////////////////////////////
//////////////////////////////////////////////////
class Stock {
   protected:
    int item_code;
    char item_name[100];
    char item_type[200];
    char brand[50];
    double qty;
    char regular_or_gram[5];
    double retail_price;
    double discount;
    double final_price;

   public:
    void check_stock();
    void add_stock();
    void increase_stock();
    void decrease_stock();
    void delete_stock();
    void show_single_item();
};
void Stock::show_single_item() {
    cout << endl;
    printElement(item_code);
    printElement(item_name);
    printElement(item_type);
    printElement(brand);
    printElement(qty);
    printElement(regular_or_gram);
    printElement(retail_price);
    printElement(discount);
    cout << '\t';
    printElement(final_price);
    cout << endl;
}
void Stock::add_stock() {
    print_dash();
    cout << "\nAdd Stock        :";
    print_dash();
    cout << "Item code          :";
    cin >> item_code;
    cout << "Item name          :";
    cin >> item_name;
    cout << "Item type          :";
    cin >> item_type;
    cout << "Brand              :";
    cin >> brand;
    cout << "Quantity           :";
    cin >> qty;
    cout << "regular_or_grams   :";
    cin >> regular_or_gram;
    cout << "Retail Price       :";
    cin >> retail_price;
    cout << "Discount           :";
    cin >> discount;
    final_price = retail_price * ((100 - discount) / 100.0);
    cout << endl;

    file.open("stock.txt", ios::out | ios::app);
    file << " " << item_code << " " << item_name << " " << item_type << " "
         << brand << " " << qty << " " << regular_or_gram << " " << retail_price
         << " " << discount << " " << final_price << "\n";
    file.close();
    cout << "Item Added Successfully";
    print_dash();
}
void Stock::check_stock() {
    print_dash();
    cout << "Check Stock";
    print_dash();

    printElement("code");
    printElement("name");
    printElement("type");
    printElement("brand");
    printElement("qty");
    printElement("r/g");
    printElement("price");
    printElement("discount");
    printElement("final price");
    cout << endl;
    file.open("stock.txt", ios::in);
    file >> item_code >> item_name >> item_type >> brand >> qty >>
        regular_or_gram >> retail_price >> discount >> final_price;
    while (!file.eof()) {
        cout << item_code << "\t\t" << item_name << "\t\t" << item_type
             << "\t\t" << brand << "\t\t" << qty << "\t\t" << regular_or_gram
             << "\t\t" << retail_price << "\t\t" << discount << "\t\t"
             << final_price << "\n";
        file >> item_code >> item_name >> item_type >> brand >> qty >>
            regular_or_gram >> retail_price >> discount >> final_price;
    }
    getch();
}
void Stock::increase_stock() {
    cout << "NOT YET IMPLEMENTED!" << endl;
    // system("cls");
    /*int item_code1;
    char item_name1[100];
    char item_type1[200];
    char brand1[50];
    double qty1;
    char regular_or_gram1[5];
    double retail_price1;
    double discount1;
    double final_price1;
    fstream file1;
    print_dash();
    cout << "Increase Stock : ";
    print_dash();
    int pid;
    cout<<"Enter Item Code :";
    cin>>pid;
    file1.open("stock1.txt",ios::app | ios::out);
    file.open("stock.txt",ios::app | ios::out);
    file>>item_code1>>item_name1>>item_type1>>brand1>>qty1>>regular_or_gram1>>retail_price1>>discount1>>final_price1;
    int x;
    int count=0;
    while(!file.eof()){
        if(pid==item_code1){
            //file>>item_code1>>item_name1>>item_type1>>brand1>>qty1>>regular_or_gram1>>retail_price1>>discount1>>final_price1;
            cout<<"Enter the quantity to add : ";
            cin>>x;
            qty1+=x;
            file1<<" "<<item_code1<<" "<<item_name1<<" "<<item_type1<<"
    "<<brand1<<" "<<qty1<<" "<<regular_or_gram1<<" "<<retail_price1<<"
    "<<discount1<<" "<<final_price1<<"\n";

            count++;
        }
    }
    cout << "Quantity Upated";
    file.close();
    file1.close();
    remove("stock.txt");
    rename("stock1.txt","stock.txt");*/
}
void Stock::decrease_stock() {
    cout << "NOT YET IMPLEMENTED!" << endl;
    // system("cls");
    /*print_dash();
    cout << "Decrease Stock : ";
    int temp;
    int qty1;
    int i = 0;
    long pos = 0;
    check_stock();
    cout << "Enter the product's code : ";
    cin >> temp;
    cout << "Enter quantity: ";
    cin >> qty1;
    file.open("stock.dat", ios::binary | ios::out | ios::in);
    while (file) {
        pos = file.tellp();
        file.read((char*)this, sizeof(*this));
        if (item_code == temp) {
            if (qty1 >= qty) {
                cout << "Not enough stock!";
                return;
            }
            qty = qty - qty1;
            file.seekp(pos);
            file.write((char*)this, sizeof(*this));
            i++;
            break;
        }
    }
    cout << "Quantity Upated";*/
}
void Stock::delete_stock() {
    cout << "NOT YET IMPLEMENTED!" << endl;
    /*int no;
    print_dash();
    cout << "Remove Item";
    print_dash();
    cout << "Enter Item Code : ";
    cin >> no;
    fstream file1;
    file1.open("temp.txt",ios::app|ios::out);
    file.open("stock.txt",ios::app|ios::in);
    file>>item_code>>item_name>>item_type>>brand>>qty>>regular_or_gram>>retail_price>>discount>>final_price;
    while(!file.eof()){
        if(no==item_code){

        }
    }*/
};

class Record {
   private:
    char cashier_name[20];
    char customer_name[30];
    char transaction_date[15];
    int item_code;
    int quantity;

   public:
    void add_record();
    void show_records();
};
void Record::add_record() {
    Stock s1;
    s1.check_stock();
    cout << endl;
    print_dash();
    cout << "\nMake a transcation";
    print_dash();
    cout << "Enter the name of cashier : ";
    cin >> cashier_name;
    cout << "Enter the name of customer : ";
    cin >> customer_name;
    cout << "Date : ";
    cin >> transaction_date;
    int num;
    cout << "How many items is customer going to buy :";
    cin >> num;
    file.open("record.txt", ios::out | ios::app);
    for (int i = 0; i < num; i++) {
        cout << "Enter the item code of item " << i + 1 << "                : ";
        cin >> item_code;
        cout << "Enter the quantity that the customer is buying       : ";
        cin >> quantity;
        file << " " << transaction_date << " " << cashier_name << " "
             << customer_name << " " << item_code << " " << quantity << endl;
    }
    cout << "Supply Added Successfully";

    file.close();
    print_dash();
}
void Record::show_records() {
    print_dash();
    cout << "Check Records";
    print_dash();
    cout << endl;
    printElement("transaction_date");
    printElement("cashier_name");
    printElement("customer_name");
    printElement("item_code");
    printElement("quantity");
    cout << endl;
    file.open("record.txt", ios::in);
    file >> transaction_date >> cashier_name >> customer_name >> item_code >>
        quantity;
    while (!file.eof()) {
        cout << transaction_date << "\t\t\t\t" << cashier_name << "\t\t\t"
             << customer_name << "\t\t\t" << item_code << "\t\t\t" << quantity
             << endl;
        file >> transaction_date >> cashier_name >> customer_name >>
            item_code >> quantity;
    }
    getch();
}

//////////////////////////////////////////////////
//////////////////////////////////////////////////
class Supply : public Stock {
   public:
    void add_supply();
    void approve_supply();
};
void Supply::add_supply() {}
void Supply::approve_supply() {}

class International_Supply : public Supply {
   private:
    char country_of_origin[50];
    char ship_number[20];
    char date_arrived_harbour[11];
    char date_arrive_store[11];

   public:
    void add_international_supply();
    void check_international_supply();
    void show_single_supply();
};
void International_Supply::show_single_supply() {
    cout << endl;
    printElement(item_code);
    printElement(item_name);
    printElement(item_type);
    printElement(brand);
    printElement(qty);
    printElement(regular_or_gram);
    printElement(retail_price);
    printElement(discount);
    printElement(final_price);
    printElement(country_of_origin);
    printElement(ship_number);
    printElement(date_arrived_harbour);
    printElement(date_arrive_store);

    cout << endl;
}
void International_Supply::check_international_supply() {
    print_dash();
    cout << "Check International Supply";
    print_dash();

    printElement("code");
    printElement("name");
    printElement("type");
    printElement("brand");
    printElement("qty");
    printElement("r/g");
    printElement("price");
    printElement("discount");
    printElement("final price");
    printElement("country");
    printElement("ship no");
    printElement("date_harbour");
    printElement("date_store");
    cout << endl;
    file.open("intersup.txt", ios::in);
    file >> item_code >> item_name >> item_type >> brand >> qty >>
        regular_or_gram >> retail_price >> discount >> final_price >>
        country_of_origin >> ship_number >> date_arrived_harbour >>
        date_arrive_store;
    while (!file.eof()) {
        cout << item_code << "\t\t" << item_name << "\t\t" << item_type
             << "\t\t" << brand << "\t\t" << qty << "\t\t" << regular_or_gram
             << "\t\t" << retail_price << "\t\t" << discount << "\t\t"
             << final_price << "\t\t" << country_of_origin << "\t\t"
             << ship_number << "\t\t" << date_arrived_harbour << "\t\t"
             << date_arrive_store << "\n";
        file >> item_code >> item_name >> item_type >> brand >> qty >>
            regular_or_gram >> retail_price >> discount >> final_price >>
            country_of_origin >> ship_number >> date_arrived_harbour >>
            date_arrive_store;
    }
    getch();
}
void International_Supply::add_international_supply() {
    print_dash();
    cout << "\nAdd an International Supply";
    print_dash();
    cout << "Item code              :";
    cin >> item_code;
    cout << "Item name              :";
    cin >> item_name;
    cout << "Item type              :";
    cin >> item_type;
    cout << "Brand                  :";
    cin >> brand;
    cout << "Quantity               :";
    cin >> qty;
    cout << "regular_or_grams       :";
    cin >> regular_or_gram;
    cout << "Retail Price           :";
    cin >> retail_price;
    cout << "Discount               :";
    cin >> discount;
    final_price = retail_price * ((100 - discount) / 100.0);
    cout << "Country of origin        :";
    cin >> country_of_origin;
    cout << "Ship number              :";
    cin >> ship_number;
    cout << "Date arrive at harbour   :";
    cin >> date_arrived_harbour;
    cout << "Date arrived ar store    :";
    cin >> date_arrive_store;
    file.open("intersup.dat", ios::app | ios::out);
    file.write(reinterpret_cast<char*>(this), sizeof(*this));
    file.close();
    cout << "Supply Added Successfully";
    file.open("intersup.txt", ios::out | ios::app);
    file << " " << item_code << " " << item_name << " " << item_type << " "
         << brand << " " << qty << " " << regular_or_gram << " " << retail_price
         << " " << discount << " " << final_price << " " << country_of_origin
         << " " << ship_number << " " << date_arrived_harbour << " "
         << date_arrive_store << "\n";
    file.close();
    print_dash();
}
//////////////////////////////////////////////////
//////////////////////////////////////////////////
class Local_Supply : public Supply {
   private:
    char factory_name[20];
    char date_departure[15];
    char date_arrival[15];
    char vehicle_number[20];

   public:
    void add_local_supply();
    void check_local_supply();
    void show_single_supply();
};
void Local_Supply::show_single_supply() {
    cout << endl;
    printElement(item_code);
    printElement(item_name);
    printElement(item_type);
    printElement(brand);
    printElement(qty);
    printElement(regular_or_gram);
    printElement(retail_price);
    printElement(discount);
    printElement(final_price);
    printElement(factory_name);
    printElement(date_departure);
    printElement(date_arrival);
    printElement(vehicle_number);

    cout << endl;
}
void Local_Supply::check_local_supply() {
    print_dash();
    cout << "Check International Supply";
    print_dash();

    printElement("code");
    printElement("name");
    printElement("type");
    printElement("brand");
    printElement("qty");
    printElement("r/g");
    printElement("price");
    printElement("discount");
    printElement("final price");
    printElement("factory");
    printElement("Departure");
    printElement("Arrival");
    printElement("Vehicle No");
    cout << endl;
    file.open("localsup.txt", ios::in);
    file >> item_code >> item_name >> item_type >> brand >> qty >>
        regular_or_gram >> retail_price >> discount >> final_price >>
        factory_name >> date_departure >> date_arrival >> vehicle_number;
    while (!file.eof()) {
        cout << item_code << "\t\t" << item_name << "\t\t" << item_type
             << "\t\t" << brand << "\t\t" << qty << "\t\t" << regular_or_gram
             << "\t\t" << retail_price << "\t\t" << discount << "\t\t"
             << final_price << "\t\t" << factory_name << "\t\t"
             << date_departure << "\t\t" << date_arrival << "\t\t"
             << vehicle_number << "\n";
        file >> item_code >> item_name >> item_type >> brand >> qty >>
            regular_or_gram >> retail_price >> discount >> final_price >>
            factory_name >> date_departure >> date_arrival >> vehicle_number;
    }
    getch();
}
void Local_Supply::add_local_supply() {
    print_dash();
    cout << "\nAdd Supply        :";
    print_dash();
    cout << "Item code          :";
    cin >> item_code;
    cout << "Item name          :";
    cin >> item_name;
    cout << "Item type          :";
    cin >> item_type;
    cout << "Brand              :";
    cin >> brand;
    cout << "Quantity           :";
    cin >> qty;
    cout << "regular_or_grams   :";
    cin >> regular_or_gram;
    cout << "Retail Price       :";
    cin >> retail_price;
    cout << "Discount           :";
    cin >> discount;
    final_price = retail_price * ((100 - discount) / 100.0);
    cout << "Factory name         :";
    cin >> factory_name;
    cout << "Date of departure     :";
    cin >> date_departure;
    cout << "Date of arrival       :";
    cin >> date_arrival;
    cout << "Vehicle number        :";
    file.open("localsup.dat", ios::app | ios::out);
    file.write(reinterpret_cast<char*>(this), sizeof(*this));
    file.close();
    cout << "Supply Added Successfully";
    print_dash();
    file.open("localsup.txt", ios::out | ios::app);
    file << " " << item_code << " " << item_name << " " << item_type << " "
         << brand << " " << qty << " " << regular_or_gram << " " << retail_price
         << " " << discount << " " << final_price << " " << factory_name << " "
         << date_departure << " " << date_arrival << " " << vehicle_number
         << "\n";
    file.close();
    print_dash();
};
//////////////////////////////////////////////////
//////////////////////////////////////////////////
class Staff : public Stock{
   protected:
    int id;
    char full_name[100];
    char position[50];
    char join_date[11];
    char username[20];
    char password[10];
};
class Owner : public Staff {
   public:
    void check_staff();
    void add_staff();
    void remove_staff();
    void show_single_menber();
    void modify_staff();
    void add_staff_only();
};

void Owner::modify_staff() {
    int n, pos, flag = 0;
    cout << "\n\nEnter the product ID of the product to modify : ";
    cin >> n;
    file.open("staff.dat", ios::in | ios::out);
    while (!file.eof()) {
        file.read(reinterpret_cast<char*>(this), sizeof(*this));
        if (id == n) {
            show_single_menber();
            pos = -1 * sizeof(*this);
            file.seekp(pos, ios::cur);
            add_staff_only();
            file.write(reinterpret_cast<char*>(this), sizeof(*this));
            cout << "Record Updated\n";
            flag = 1;
        }
    }
    file.close();
    if (flag == 0) cout << "\n\nSorry!!! Record Not Found ";
    getch();
}
void Owner::check_staff() {
    cout << "Check Staff Members";
    print_dash();
    // cout<<endl<<setw(8)<<"id"<<setw(8)<<"full_name"<<setw(8)<<"position"<<setw(8)<<"join_date"<<setw(8)<<"username"<<setw(8)<<"password";
    printElement("id");
    printElement("full_name");
    printElement("position");
    printElement("join_date");
    printElement("username");
    printElement("password");
    cout << "\n----------------------------------------------------------------"
            "------------------------------------------------------------------"
            "---";
    file.open("staff.dat", ios::in);
    file.seekg(0);
    file.read(reinterpret_cast<char*>(this), sizeof(*this));
    while (!file.eof()) {
        show_single_menber();
        file.read(reinterpret_cast<char*>(this), sizeof(*this));
    }
    file.close();
}
void Owner::show_single_menber() {
    cout << endl;
    printElement(id);
    printElement(full_name);
    cout << '\t';
    printElement(position);
    cout << '\t';
    printElement(join_date);
    cout << '\t';
    printElement(username);
    cout << '\t';
    printElement(password);
    cout << endl;
}
void Owner::add_staff_only() {
    print_dash();
    cout << "\nAdd Staff Members";
    print_dash();
    cout << "Enter id             : ";
    cin >> id;
    cout << "Enter full name      : ";
    cin >> full_name;
    cout << "Position             : ";
    cin >> position;
    cout << "Join Date            : ";
    cin >> join_date;
    cout << "Username             : ";
    cin >> username;
    cout << "Password             : ";
    cin >> password;
}
void Owner::add_staff() {
    print_dash();
    cout << "\nAdd Staff Members";
    print_dash();
    cout << "Enter id             : ";
    cin >> id;
    cout << "Enter full name      : ";
    cin >> full_name;
    cout << "Position             : ";
    cin >> position;
    cout << "Join Date            : ";
    cin >> join_date;
    cout << "Username             : ";
    cin >> username;
    cout << "Password             : ";
    cin >> password;
    file.open("staff.dat", ios::app | ios::out);
    file.write(reinterpret_cast<char*>(this), sizeof(*this));
    file.close();
    cout << "Staff Member Added Successfully";
    print_dash();
}
void Owner::remove_staff() {
    int no;
    print_dash();
    cout << "Remove Staff Members";
    print_dash();
    cout << "Enter Member id : ";
    cin >> no;
    file.open("staff.dat", ios::in | ios::out);
    fstream fp2;
    fp2.open("Temp.dat", ios::out);
    file.seekg(0, ios::beg);
    while (file.read((char*)this, sizeof(*this))) {
        if (id != no) {
            fp2.write((char*)this, sizeof(*this));
        }
    }
    fp2.close();
    file.close();
    remove("staff.dat");
    rename("Temp.dat", "staff.dat");
    cout << "\nRecord Deleted ..";
    getch();
}

//////////////////////////////////////////////////
//////////////////////////////////////////////////
class Manager : public Staff {
   public:
    void check_staff();
};
void Manager::check_staff() {
    Owner owner;
    owner.check_staff();
}
//////////////////////////////////////////////////
//////////////////////////////////////////////////
class Cashier : public Staff {
   public:
};
class Floor_Worker : public Staff {
   public:
};
//////////////////////////////////////////////////
//////////////////////////////////////////////////

void owner_profile() {
    while (1) {
        system("cls");
        print_dash();
        cout << "WELCOME TO OWNER PROFILE";
        print_dash();
        cout << "Select task";
        print_dash();
        cout << "STAFF";
        print_dash();
        cout << "1-Add Staff Member";
        cout << endl;
        cout << "2-Check Staff Member";
        cout << endl;
        cout << "3-Delete Staff Member";
        cout << endl;
        cout << "4-Modify details of Staff";
        cout << endl;
        cout << endl;
        cout << "SUPPLY";
        print_dash();
        cout << "5-Add Local Supply";
        cout << endl;
        cout << "6-Check Local Supply";
        cout << endl;
        cout << "7-Add International Supply";
        cout << endl;
        cout << "8-Check International Supply";
        cout << endl;
        cout << endl;
        cout << "STOCK";
        print_dash();
        cout << "9-Check Stock";
        cout << endl;
        cout << "10-Add Stock";
        cout << endl;
        cout << "11-Delete Stock";
        cout << endl;
        cout << "12-Increase Stock";
        cout << endl;
        cout << "13-Decrease Stock";
        cout << endl;
        cout << endl;
        cout << "TRANSACTIONS";
        print_dash();
        cout << "14-Make a transaction";
        cout << endl;
        cout << "15-View Transaction Records";
        cout << endl;
        cout << "16-Exit";
        cout << endl;
        cout << endl;
        int opt;
        cout << "ENTER THE OPTION : ";
        cin >> opt;
        switch (opt) {
            case 1: {
                system("cls");
                Owner owner;
                owner.add_staff();
                getch();
            } break;

            case 2: {
                system("cls");
                Owner owner;
                owner.check_staff();
                getch();
            } break;
            case 3: {
                system("cls");
                Owner owner;
                owner.remove_staff();
                getch();
            } break;
            case 4: {
                system("cls");
                Owner owner;
                owner.modify_staff();
                getch();
            } break;
            case 5: {
                system("cls");
                Local_Supply supply;
                supply.add_local_supply();
                getch();
            } break;
            case 6: {
                system("cls");
                Local_Supply supply;
                supply.check_local_supply();
                getch();
            } break;
            case 7: {
                system("cls");
                International_Supply supply;
                supply.add_international_supply();
                getch();
            } break;
            case 8: {
                system("cls");
                International_Supply supply;
                supply.check_international_supply();
                getch();
            } break;
            case 9: {
                system("cls");
                Stock stock;
                stock.check_stock();
                getch();
            } break;
            case 10: {
                system("cls");
                Stock stock;
                stock.add_stock();
                getch();
            } break;
            case 11: {
                system("cls");
                Stock stock;
                stock.delete_stock();
                getch();
            } break;
            case 12: {
                system("cls");
                Stock stock;
                stock.increase_stock();
                getch();
            } break;
            case 13: {
                system("cls");
                Stock stock;
                stock.decrease_stock();
                getch();
            } break;
            case 14: {
                system("cls");
                Record record;
                record.add_record();
                getch();

            } break;
            case 15: {
                system("cls");
                Record record;
                record.show_records();
                getch();
            } break;
            case 16: {
                system("cls");
                main_menu();
            } break;
            default:
                cout << "Enter a valid option !";
        }
    }
}
void manager_profile() {
    while (1) {
        system("cls");
        print_dash();
        cout << "WELCOME TO MANAGER PROFILE";
        print_dash();
        cout << "Select task";
        print_dash();
        cout << "STAFF";
        print_dash();
        
        cout << "1-Check Staff Member";
        
        
        cout << endl;
        cout << endl;
        cout << "SUPPLY";
        print_dash();
        cout << "2-Add Local Supply";
        cout << endl;
        cout << "3-Check Local Supply";
        cout << endl;
        cout << "4-Add International Supply";
        cout << endl;
        cout << "5-Check International Supply";
        cout << endl;
        cout << endl;
        cout << "STOCK";
        print_dash();
        cout << "6-Check Stock";
        cout << endl;
        cout << "7-Add Stock";
        cout << endl;
        cout << "8-Delete Stock";
        cout << endl;
        cout << "9-Increase Stock";
        cout << endl;
        cout << "10-Decrease Stock";
        cout << endl;
        cout << endl;
        cout << "TRANSACTIONS";
        print_dash();
        cout << "11-Make a transaction";
        cout << endl;
        cout << "12-View Transaction Records";
        cout << endl;
        cout << "13-Exit";
        cout << endl;
        cout << endl;
        int opt;
        cout << "ENTER THE OPTION : ";
        cin >> opt;
        switch (opt) {
            

            case 1: {
                system("cls");
                Owner owner;
                owner.check_staff();
                getch();
            } break;
            
            case 2: {
                system("cls");
                Local_Supply supply;
                supply.add_local_supply();
                getch();
            } break;
            case 3: {
                system("cls");
                Local_Supply supply;
                supply.check_local_supply();
                getch();
            } break;
            case 4: {
                system("cls");
                International_Supply supply;
                supply.add_international_supply();
                getch();
            } break;
            case 5: {
                system("cls");
                International_Supply supply;
                supply.check_international_supply();
                getch();
            } break;
            case 6: {
                system("cls");
                Stock stock;
                stock.check_stock();
                getch();
            } break;
            case 7: {
                system("cls");
                Stock stock;
                stock.add_stock();
                getch();
            } break;
            case 8: {
                system("cls");
                Stock stock;
                stock.delete_stock();
                getch();
            } break;
            case 9: {
                system("cls");
                Stock stock;
                stock.increase_stock();
                getch();
            } break;
            case 10: {
                system("cls");
                Stock stock;
                stock.decrease_stock();
                getch();
            } break;
            case 11: {
                system("cls");
                Record record;
                record.add_record();
                getch();

            } break;
            case 12: {
                system("cls");
                Record record;
                record.show_records();
                getch();
            } break;
            case 13: {
                system("cls");
                main_menu();
            } break;
            default:
                cout << "Enter a valid option !";
        }
    }
}
void chashier_profile() {
    while (1) {
        system("cls");
        print_dash();
        cout << "WELCOME TO CASHIER PROFILE";
        print_dash();
        cout << "Select task";
        print_dash();
        cout << "SUPPLY";
        print_dash();
        cout << "1-Add Local Supply";
        cout << endl;
        cout << "2-Check Local Supply";
        cout << endl;
        cout << "3-Add International Supply";
        cout << endl;
        cout << "4-Check International Supply";
        cout << endl;
        cout << endl;
        cout << "STOCK";
        print_dash();
        cout << "5-Check Stock";
        cout << endl;
        cout << "6-Add Stock";
        cout << endl;
        cout << "7-Delete Stock";
        cout << endl;
        cout << "8-Increase Stock";
        cout << endl;
        cout << "9-Decrease Stock";
        cout << endl;
        cout << endl;
        cout << "TRANSACTIONS";
        print_dash();
        cout << "10-Make a transaction";
        cout << endl;
        cout << "11-View Transaction Records";
        cout << endl;
        cout << "12-Exit";
        cout << endl;
        cout << endl;
        int opt;
        cout << "ENTER THE OPTION : ";
        cin >> opt;
        switch (opt) {
            case 1: {
                system("cls");
                Local_Supply supply;
                supply.add_local_supply();
                getch();
            } break;
            case 2: {
                system("cls");
                Local_Supply supply;
                supply.check_local_supply();
                getch();
            } break;
            case 3: {
                system("cls");
                International_Supply supply;
                supply.add_international_supply();
                getch();
            } break;
            case 4: {
                system("cls");
                International_Supply supply;
                supply.check_international_supply();
                getch();
            } break;
            case 5: {
                system("cls");
                Stock stock;
                stock.check_stock();
                getch();
            } break;
            case 6: {
                system("cls");
                Stock stock;
                stock.add_stock();
                getch();
            } break;
            case 7: {
                system("cls");
                Stock stock;
                stock.delete_stock();
                getch();
            } break;
            case 8: {
                system("cls");
                Stock stock;
                stock.increase_stock();
                getch();
            } break;
            case 9: {
                system("cls");
                Stock stock;
                stock.decrease_stock();
                getch();
            } break;
            case 10: {
                system("cls");
                Record record;
                record.add_record();
                getch();

            } break;
            case 11: {
                system("cls");
                Record record;
                record.show_records();
                getch();
            } break;
            case 12: {
                system("cls");
                main_menu();
            } break;
            default:
                cout << "Enter a valid option !";
        }
    }
}
void floor_worker_profile() {
    while (1) {
        system("cls");
        print_dash();
        cout << "WELCOME TO FLOOR WORKER PROFILE";
        print_dash();
        cout << "Select task";
        print_dash();
        cout << "SUPPLY";
        print_dash();
        cout << "1-Add Local Supply";
        cout << endl;
        cout << "2-Check Local Supply";
        cout << endl;
        cout << "3-Add International Supply";
        cout << endl;
        cout << "4-Check International Supply";
        cout << endl;
        cout << endl;
        cout << "STOCK";
        print_dash();
        cout << "5-Check Stock";
        cout << endl;
        cout << "6-Increase Stock";
        cout << endl;
        cout << endl;

        int opt;
        cout << "ENTER THE OPTION : ";
        cin >> opt;
        switch (opt) {
            case 1: {
                system("cls");
                Local_Supply supply;
                supply.add_local_supply();
                getch();
            } break;
            case 2: {
                system("cls");
                Local_Supply supply;
                supply.check_local_supply();
                getch();
            } break;
            case 3: {
                system("cls");
                International_Supply supply;
                supply.add_international_supply();
                getch();
            } break;
            case 4: {
                system("cls");
                International_Supply supply;
                supply.check_international_supply();
                getch();
            } break;
            case 5: {
                system("cls");
                Stock stock;
                stock.check_stock();
                getch();
            } break;

            case 6: {
                system("cls");
                Stock stock;
                stock.increase_stock();
                getch();
            } break;

            case 12: {
                system("cls");
                main_menu();
            } break;
            default:
                cout << "Enter a valid option !";
        }
    }
}
void main_menu() {
    system("cls");
    print_dash();
    cout << "WELCOME TO ASKA STORES";
    print_dash();
    cout << endl;
    cout << "Select your Positon";
    print_dash();
    cout << "1-Owner";
    cout << endl;
    cout << "2-Manager";
    cout << endl;
    cout << "3-Cashier";
    cout << endl;
    cout << "4-Floor Worker";
    cout << endl;
    cout << "5-Exit";
    cout << endl;
    int option;
    cout << "Enter the position : ";
    cin >> option;
    switch (option) {
        case 1: {
            system("cls");
            string password;
            string username;
            cout << "Enter username : ";
            cin >> username;
            cout << "Enter Password :";
            cin >> password;
            if (username == "owner" && password == "owner") {
                owner_profile();
            } else {
                cout << "Wrong Usename or Password";
            }

        } break;
        case 2: {
            system("cls");
            string password;
            string username;
            cout << "Enter username : ";
            cin >> username;
            cout << "Enter Password :";
            cin >> password;
            if (username == "manager" && password == "manager") {
                manager_profile();
            } else {
                cout << "Wrong Usename or Password";
            }

        } break;
        case 3: {
            system("cls");
            string password;
            string username;
            cout << "Enter username : ";
            cin >> username;
            cout << "Enter Password :";
            cin >> password;
            if (username == "cashier" && password == "cashier") {
                chashier_profile();
            } else {
                cout << "Wrong Usename or Password";
            }

        } break;
        case 4: {
            system("cls");
            string password;
            string username;
            cout << "Enter username : ";
            cin >> username;
            cout << "Enter Password :";
            cin >> password;
            if (username == "floor" && password == "floor") {
                floor_worker_profile();
            } else {
                cout << "Wrong Usename or Password";
            }

        } break;
        case 5:
            return;
            break;
        default:
            cout << "Enter a valid option";
    }
}
int main() { main_menu(); }