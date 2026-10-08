#include <iostream>
using namespace std;

class ItemNode {
public:
    string item;
    ItemNode* next;

    ItemNode(string value) {
        item = value;
        next = NULL;
    }
};

class SectionNode {
public:
    string sectionName;
    ItemNode* itemFirst;
    SectionNode* next;

    SectionNode(string value) {
        sectionName = value;
        itemFirst = NULL;
        next = NULL;
    }
};

class StoreNode {
public:
    string storeName;
    SectionNode* sectionFirst;
    StoreNode* next;

    StoreNode(string value) {
        storeName = value;
        sectionFirst = NULL;
        next = NULL;
    }
};

class StoreManagement {
public:
    StoreNode* firstStore;

    StoreManagement() {
        firstStore = NULL;
    }

    void addStore(string storeName) {
        StoreNode* newStore = new StoreNode(storeName);

        if (firstStore == NULL) {
            firstStore = newStore;
            return;
        }

        StoreNode* temp = firstStore;

        while (temp->next != NULL)
            temp = temp->next;

        temp->next = newStore;
    }

    StoreNode* searchStore(string storeName) {
        StoreNode* temp = firstStore;

        while (temp != NULL) {
            if (temp->storeName == storeName)
                return temp;

            temp = temp->next;
        }

        return NULL;
    }

    void addSection(string storeName, string sectionName) {
        StoreNode* store = searchStore(storeName);

        if (store == NULL) {
            cout << "Store not found." << endl;
            return;
        }

        SectionNode* newSection = new SectionNode(sectionName);

        if (store->sectionFirst == NULL) {
            store->sectionFirst = newSection;
            return;
        }

        SectionNode* temp = store->sectionFirst;

        while (temp->next != NULL)
            temp = temp->next;

        temp->next = newSection;
    }

    SectionNode* searchSection(StoreNode* store, string sectionName) {
        SectionNode* temp = store->sectionFirst;

        while (temp != NULL) {
            if (temp->sectionName == sectionName)
                return temp;

            temp = temp->next;
        }

        return NULL;
    }

    void addItem(string storeName, string sectionName, string itemName) {
        StoreNode* store = searchStore(storeName);

        if (store == NULL) {
            cout << "Store not found." << endl;
            return;
        }

        SectionNode* section = searchSection(store, sectionName);

        if (section == NULL) {
            cout << "Section not found." << endl;
            return;
        }

        ItemNode* newItem = new ItemNode(itemName);

        if (section->itemFirst == NULL) {
            section->itemFirst = newItem;
            return;
        }

        ItemNode* temp = section->itemFirst;

        while (temp->next != NULL)
            temp = temp->next;

        temp->next = newItem;
    }

    void removeItem(string storeName, string sectionName, string itemName) {
        StoreNode* store = searchStore(storeName);

        if (store == NULL) {
            cout << "Store not found." << endl;
            return;
        }

        SectionNode* section = searchSection(store, sectionName);

        if (section == NULL) {
            cout << "Section not found." << endl;
            return;
        }

        if (section->itemFirst == NULL) {
            cout << "No items in this section." << endl;
            return;
        }

        if (section->itemFirst->item == itemName) {
            ItemNode* temp = section->itemFirst;
            section->itemFirst = section->itemFirst->next;
            delete temp;
            return;
        }

        ItemNode* current = section->itemFirst;

        while (current->next != NULL) {
            if (current->next->item == itemName) {
                ItemNode* temp = current->next;
                current->next = temp->next;
                delete temp;
                return;
            }

            current = current->next;
        }

        cout << "Item not found." << endl;
    }

    void displaySectionItems(string storeName, string sectionName) {
        StoreNode* store = searchStore(storeName);

        if (store == NULL) {
            cout << "Store not found." << endl;
            return;
        }

        SectionNode* section = searchSection(store, sectionName);

        if (section == NULL) {
            cout << "Section not found." << endl;
            return;
        }

        ItemNode* temp = section->itemFirst;

        cout << "Items in " << sectionName << ": ";

        while (temp != NULL) {
            cout << temp->item << " ";
            temp = temp->next;
        }

        cout << endl;
    }

    void displayStoreItems(string storeName) {
        StoreNode* store = searchStore(storeName);

        if (store == NULL) {
            cout << "Store not found." << endl;
            return;
        }

        SectionNode* section = store->sectionFirst;

        cout << "Items in Store " << storeName << ":" << endl;

        while (section != NULL) {
            cout << section->sectionName << ": ";

            ItemNode* item = section->itemFirst;

            while (item != NULL) {
                cout << item->item << " ";
                item = item->next;
            }

            cout << endl;

            section = section->next;
        }
    }
};

int main() {
    StoreManagement system;

    system.addStore("Islamabad");
    system.addStore("Lahore");

    system.addSection("Islamabad", "Grocery");
    system.addSection("Islamabad", "Toys");
    system.addSection("Lahore", "Fruits");

    system.addItem("Islamabad", "Grocery", "Milk");
    system.addItem("Islamabad", "Grocery", "Bread");
    system.addItem("Islamabad", "Toys", "Car");
    system.addItem("Lahore", "Fruits", "Apple");
    system.addItem("Lahore", "Fruits", "Banana");

    system.displaySectionItems("Islamabad", "Grocery");

    system.displayStoreItems("Islamabad");

    system.removeItem("Islamabad", "Grocery", "Bread");

    cout << endl << "After removing Bread:" << endl;

    system.displayStoreItems("Islamabad");

    return 0;
}
