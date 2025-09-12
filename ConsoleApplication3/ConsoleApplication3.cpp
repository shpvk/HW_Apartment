#include <iostream>

class Room
{
private:
    char* name;
    int square_meters;
    bool glue_ceiling;
public:
    Room()
    {
        name = nullptr;
        square_meters = 0;
        glue_ceiling = false;
    }
    ~Room()
    {
        delete[] name;
    }
    void Init(const char* name, int square_meters, bool glue_ceiling)
    {
        this->name = new char[strlen(name) + 1];
        strcpy_s(this->name, strlen(name) + 1, name);

        this->square_meters = square_meters;
        this->glue_ceiling = glue_ceiling;

    }
    int getArea()
    { 
        return square_meters;
    }

};

class Apartment
{
private:
    Room* rooms;
    int rooms_count;
public:
    Apartment()
    {
        rooms = nullptr;
        rooms_count = 0;
    }
    void SetRooms(Room* rooms, int rooms_count) 
    {
        this->rooms = rooms;
        this->rooms_count = rooms_count;
    }
    
    int TotalArea() 
    {
        int sum = 0;
        for (int i = 0; i < rooms_count; ++i)
        {
            sum += rooms[i].getArea();
        }
        return sum;
    }

};

class Wallpaper
{
private:
    char* name;
    int roll_length;
    int roll_width;
    int price;
public:
    Wallpaper()
    {
        name = nullptr;
        roll_length = 0;
        roll_width = 0;
        price = 0;
    }
    Wallpaper(const char* name, int roll_length, int roll_width, int price)
    {
        this->name = new char[strlen(name) + 1];
        strcpy_s(this->name, strlen(name) + 1, name);

        this->roll_length = roll_length;
        this->roll_width = roll_width;
        this->price = price;
    }
    ~Wallpaper()
    {
        delete[] name;
    }

    int GetRollArea()
    { 
        return roll_length * roll_width;
    }

    int RollsNeeded(int area)
    {
        int rollArea = GetRollArea();
        return (area + rollArea - 1) / rollArea;
    }

    int TotalCost(int area)
    {
        return RollsNeeded(area) * price;
    }
};

int main()
{   
    std::cout << "Enter the number of rooms in the apartment: ";
    int rooms_amount;
    std::cin >> rooms_amount;


    Room* rooms = new Room[rooms_amount];
    Apartment apartment1;

    char name[100];
    int square_meters;
    bool glue_ceiling;
    for (int i = 0; i < rooms_amount; ++i)
    {
        std::cout << "Enter name: ";
        std::cin >> name;

        std::cout << "Enter square meters: ";
        std::cin >> square_meters;

        std::cout << "Enter glue ceiling (0 - false, 1 - true): ";
        std::cin >> glue_ceiling;
        
        rooms[i].Init(name, square_meters, glue_ceiling);
    }
    apartment1.SetRooms(rooms, rooms_amount);

    char wallpaper_name[100];
    int len, wid, price;
    std::cout << "Enter wallpaper name: ";
    std::cin >> wallpaper_name;
    std::cout << "Roll length: ";
    std::cin >> len;
    std::cout << "Roll width: ";
    std::cin >> wid;
    std::cout << "Price per roll: ";
    std::cin >> price;

    Wallpaper wallpaper(wallpaper_name, len, wid, price);
    int area = apartment1.TotalArea();
    std::cout << "Rolls needed: " << wallpaper.RollsNeeded(area) << "\n";
    std::cout << "Total cost: " << wallpaper.TotalCost(area) << "\n";
    std::cout << "Total area: " << apartment1.TotalArea();

    delete[] rooms;
}
