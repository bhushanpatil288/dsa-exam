#include <iostream>
#include <vector>

using namespace std;

// template <typename T>
class GroceryProduct{
    protected:
        int productID, price;
        string productName;
    public:
        GroceryProduct(int productID, string productName, int price){
            this->productID = productID;
            this->productName = productName;
            this->price = price;
        }
        void viewProcutDetails(){
            cout << "\n\n======================\n";
            cout << "Product ID: " << this->productID << "\n";
            cout << "Product Name: " << this->productName << "\n";
            cout << "Product Price: " << this-> price << "\n";
            cout << "======================\n";
        }
        int getProductId(){
            return this->productID; 
        }
        void updateProduct(string productName, int price){
            this->productName = productName;
            this->price = price;
            cout << "\n *Product:" << productName <<  " has been updated\n";
        }
};

int main(){
    cout << "\n\n            Grocery Product Invetory Sytem\n";
    vector<GroceryProduct> inventory;

    int choice;
    do {
        cout << "\n1. Add a product\n";
        cout << "2. Display all prodcuts\n";
        cout << "3. Remove a product: \n";
        cout << "4. Update a product: \n";
        cout << "5. Exit the program: \n\n";
        cout << "Your Choice: ";
        cin >> choice;

        switch(choice){
            // adding a product(complete)
            case 1:{
                int productID, price;
                string productName;

                cout << "Enter the ID of product: ";
                cin >> productID;
                cin.ignore();
                cout << "Enter the name of the product: ";
                getline(cin, productName);
                cout << "Enter the price of the product: ";
                cin >> price;

                GroceryProduct newProduct(productID, productName, price);

                inventory.push_back(newProduct);
                cout << "\n\n *Product " << productName << " has been added to invontory.\n";

                break;
            }
            // displaying a products
            case 2:{
                if (inventory.empty()){
                    cout << "Inventory is currently empty\n";
                    break;
                }

                for (auto& product: inventory){
                    product.viewProcutDetails();
                }
                break;
            }
            case 3:{
                if (inventory.empty()){
                    cout << "Inventory is currently empty\n";
                    break;
                }

                int productID;
                cout << "Enter the product ID: ";
                cin >> productID;

                bool not_found = true;

                for(int i = 0; i < inventory.size(); i++){
                    if(inventory[i].getProductId() == productID){
                        inventory.erase(inventory.begin() + i);
                        cout << "\n *Product has been removed !\n";
                        not_found = false;
                    }
                }

                if(not_found){
                    cout << "\n\n *This product doesn't exist in inventory\n";
                }
                break;
            }
            case 4:{
                if (inventory.empty()){
                    cout << "Inventory is currently empty\n";
                    break;
                }

                int productID;
                cout << "Enter the product ID: ";
                cin >> productID;

                bool not_found = true;

                for(int i = 0; i < inventory.size(); i++){
                    if(inventory[i].getProductId() == productID){
                        string productName;
                        int price;
                        cin.ignore();
                        cout << "Enter the new product name: ";
                        getline(cin, productName);
                        cout << "Enter the new Product price: ";
                        cin >> price;
                        inventory[i].updateProduct(productName, price);
                        not_found = false;
                    }
                }

                if(not_found){
                    cout << "This product doesn't exist in inventory\n";
                }
                break;
                
            }
            case 5:{
                break;
            }
            default:{
                cout << "\n\n================\n";
                cout << "Invalid Choice!\n";
                cout << "================\n";
            }
        }
    } while (choice != 5);

    cout << "\n\n\n Thank you for using this program\n\n";
    return 0;
}