#include <bits/stdc++.h>
#include <conio.h>
using namespace std;

// guns
vector<string> guns = {"AK-47", "M4A4", "M4A1-S", "AUG", "FAMAS", "Galil AR", "SG-553"};

// mag size
vector<int> mags = {30, 30, 25, 30, 25, 35, 30};

// bullet type
vector<string> type = {"7.62 mm", "5.56 mm", "5.56 mm", "5.56 mm", "5.56 mm", "5.56 mm", "7.62 mm"};

// made in
vector<string> madeIn = {
    "Soviet Union",
    "United States",
    "United States",
    "Australia",
    "France",
    "Israel",
    "Switzerland"};

// prices
vector<int> prices = {2700, 3100, 2900, 3300, 2100, 2000, 2900};

// skins
vector<vector<string>> skins = {{"Neon Rider", "Fire Serpent", "Neon Revolution"}, {"Desolate Space", "The Emperor", "Poison"}, {"HyperBeast", "PrintStream", "Hot Rod"}, {"Richochet", "Flame", "Copperhead"}, {"Neural Net", "BoomKitty", "Gold Ester"}, {"SandStorm", "FireFight", "Criminal Damage"}, {"Pebble", "Cyrex", "Tornado"}};

// info displayer
void displayInfo(int n)
{
    cout << "Gun Info:" << endl;
    cout << "Magazine Size: " << mags[n - 1] << endl;
    cout << "Bullet Type: " << type[n - 1] << endl;
    cout << "Made in: " << madeIn[n - 1] << endl;
    cout << "Price: " << prices[n - 1] << "$" << endl;
}

// total mags present
int total_mags = 0;

// gun
string gun;

// capacity
int cap = 0;

// equiped skin
string curr = "Vanilla";

// money
int money = 10000;

// firing mode current
int firing_mode = 1;

// loaded mag
stack<int> loaded_mag;

// stats
int bullets_used = 0;
int mags_left = total_mags;
int bullets_left = cap * total_mags;

// loadout viewer
void displayLoadout()
{
    cout << "Gun: " << gun << endl;
    cout << "Magazines: " << total_mags << endl;
    cout << "Bullets: " << cap * total_mags << endl;
    cout << "Skin: " << curr << endl;
}

// fire
void fire(int mode)
{
    if (mode == 1)
    {
        // auto
        while (!loaded_mag.empty())
        {
            loaded_mag.pop();
            cout << "Bullet Fired!" << endl;
            bullets_used++;
        }
        cout << "Magazine Empty! " << endl;
    }
    else if (mode == 2)
    {
        // single
        if (!loaded_mag.empty())
        {
            loaded_mag.pop();
            cout << "Bullet Fired!" << endl;
            bullets_used++;
        }
        else
        {
            cout << "Magazine Empty! " << endl;
        }
    }
}

// change firing mode

void firing_mode_curr()
{
    cout << "Select a firing mode! " << endl;
    cout << "1. Auto \n2. Single" << endl;
    int mode;
    cin >> mode;
    if (mode == 1)
    {
        firing_mode = 1;
        cout << "Firing mode switched to Auto! " << endl;
    }

    else if (mode == 2)
    {
        firing_mode = 2;
        cout << "Firing mode switched to Single! " << endl;
    }
}

// reload
void reload()
{
    int needed = cap - loaded_mag.size();
    if (!needed)
        cout << "Magazine Full! " << endl;
    else
    {
        while (needed)
        {
            if (bullets_left)
            {
                loaded_mag.push(1);
                bullets_left--;
                needed--;
            }
            else
            {
                cout << "Out of bullets! " << endl;
                break;
            }
        }
    }
}

// gun system
void gun_sys()
{

    cout << "1. Fire \n2. Reload \n3. Change Firing Mode \n0. Exit" << endl;
    int option;
    cin >> option;
    if (option == 1)
    {
        fire(firing_mode);
        gun_sys();
    }
    else if (option == 2)
    {
        reload();
        gun_sys();
    }
    else if (option == 3)
    {
        firing_mode_curr();
        gun_sys();
    }
    else if (option == 0)
    {
        return;
    }
    else
    {
        cout << "Enter a valid choice!" << endl;
        gun_sys();
    }
}

// view shop
void shop(int gun_number)
{
    cout << "You have: " << money << "$" << endl;
    cout << "What do you want to buy? " << endl;
    cout << "1. Magazines \n2. Skins \nEnter 0 to Exit Shop! " << endl;
    int val;
    cin >> val;
    if (val == 1)
    {
        // magazines
        cout << "You have: " << money << "$" << endl;
        cout << "How many magazines do you want to buy? " << endl;
        int mags;
        cin >> mags;
        if (mags * 100 > money)
        {
            cout << "Not enough money! " << endl;
            shop(gun_number);
            return;
        }
        else
        {
            money -= mags * 100;
            total_mags += mags;
            bullets_left += cap * mags;
            cout << mags << " magazines bought! " << endl;
            cout << "Total magazines: " << total_mags << endl;
            shop(gun_number);
        }
    }
    else if (val == 2)
    {
        if (money < 1500)
        {
            cout << "Not Enough Money!" << endl;
            shop(gun_number);
            return;
        }
        cout << "You have: " << money << "$" << endl;
        cout << "Select the skin you want to use! " << endl;
        for (int i = 0; i < 3; i++)
        {
            cout << i + 1 << ". " << skins[gun_number - 1][i] << ": 1500$\n";
        }
        int selected;
        cin >> selected;
        cout << "Skin Equipped! " << endl;
        curr = skins[gun_number - 1][selected - 1];
        money -= 1500;
        shop(gun_number);
    }
    else if (val == 0)
    {
        return;
    }
    else
    {
        cout << "Enter a valid number! " << endl;
    }
}

void displayStats()
{
    cout << "You Used: " << gun << "\nTotal Bullets Used: " << bullets_used << "\nTotal Bullets Left: " << bullets_left << "\nMoney Spent: " << 10000 - money << "\nMoney Left: " << money << endl;
    ;
}

int main()
{
    cout << "You have: " << money << "$" << endl;
    cout << "Select the assault rifle you want to use! " << endl;
    cout << "1. AK-47 \n2. M4A4 \n3. M4A1-S \n4. AUG \n5. FAMAS \n6. Galil AR \n7. SG-553" << endl;
    int k;
    cin >> k;
    gun = guns[k - 1];
    cap = mags[k - 1];
    if (k <= 0 || k > 7)
    {
        cout << "Please Enter a valid Gun number! " << endl;
        return 0;
    }
    cout << "You are equiped with " << guns[k - 1] << " !" << endl;
    displayInfo(k);
    money -= prices[k - 1];
    shop(k);
    cout << "Your Loadout is ->" << endl;
    displayLoadout();
    gun_sys();
    displayStats();
}