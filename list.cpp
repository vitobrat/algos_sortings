#include "list.h"
#include <iostream>
#include <sstream>
#include <chrono>

using namespace std;

List::List(){

}

//проверка ввода на целое число
int checkInput(){
    int input;
    try {
        cin >> input;
        if (cin.fail()) {
            throw 1;
        }
    } catch (int exeption) {
        cout << "ERROR!!!";
        exit(0);
    }
    cin.sync();
    cout << "\n";
    return input;
}

//выводит список на экран
void List::printList(){
    cout << "List: ";
    List *cur = head;
    while(cur){
        cout << cur->data << " ";
        cur = cur->next;
    }
    cout << "\n";
}

//создает список из рандомных чисел размера N
void List::createList(unsigned N){
    if (head != nullptr){
        deleteList();
    }
    size = N;
    auto start = std::chrono::duration_cast<std::chrono::nanoseconds>(std::chrono::system_clock::now().time_since_epoch()).count();
    List *tail = nullptr;
    srand(time(NULL));
    for (int i = 0; i < size; i++){
        head = new List;
        head->data = rand() % 100;
        head->next = tail;
        if(tail){
            tail->prev = head;
        }
        tail = head;
    }
    if(size != 0) head->prev = nullptr;
    auto end = std::chrono::duration_cast<std::chrono::nanoseconds>(std::chrono::system_clock::now().time_since_epoch()).count();
    cout << "time spent to creat list in nanoseconds: " << end - start << "ns\n";
}

//создает список из чисел, записанных в строку
void List::createList(string str){
    if (head != nullptr){
        deleteList();
    }
    auto start = std::chrono::duration_cast<std::chrono::nanoseconds>(std::chrono::system_clock::now().time_since_epoch()).count();
    List *tail = nullptr;
    istringstream iss(str);
    int num;
    while (iss >> num) {
        head = new List;
        head->data = num;
        head->prev = tail;
        if(tail){
            tail->next = head;
        }
        tail = head;
        size++;
    }
    if(size>0) {
        head->next = nullptr;
        while (head->prev) {
            head = head->prev;
        }
        auto end = std::chrono::duration_cast<std::chrono::nanoseconds>(
                       std::chrono::system_clock::now().time_since_epoch()).count();
        cout << "time spent to creat list in nanoseconds: " << end - start << "ns\n";
    }else{
        head = nullptr;
    }
}

//находит ссылку элемента по индексу
List* List::listItem(unsigned int index) {
    int p = 0;
    List* cur = head;
    while(p != index){
        cur = cur->next;
        p++;
    }
    return cur;
}

//добавляет элемент в список. Индекс, по которому нужно добавить элемент справшивается в самой функции
void List::addValueAtList(){
    cout << "Input new index: ";
    int index = checkInput();
    if (!(index >= 1 && index <= size + 1)){
        cout << "Wrong input! Try again.\n";
        return;
    }
    cout << "Input new value: ";
    int value = checkInput();
    List *addItem = new List;
    addItem->data = value;
    auto start = std::chrono::duration_cast<std::chrono::nanoseconds>(std::chrono::system_clock::now().time_since_epoch()).count();
    if(index > size){
        List *item = listItem(size - 1);
        item->next = addItem;
        addItem->prev = item;
        addItem->next = nullptr;
    }else if(index == 1){
        head->prev = addItem;
        addItem->next = head;
        addItem->prev = nullptr;
        head = addItem;
    }else{
        List *item = listItem(index - 1);
        addItem->next = item;
        addItem->prev = item->prev;
        item->prev->next = addItem;
        item->prev = addItem;
    }
    auto end = std::chrono::duration_cast<std::chrono::nanoseconds>(std::chrono::system_clock::now().time_since_epoch()).count();
    cout << "time spent to add element in list in nanoseconds: " << end - start << "ns\n";
    size++;
}


void List::changeValueAtList(){
    cout << "Input 2 indexes you wanna change(by enter):";
    int index1 = checkInput();
    int index2 = checkInput();
    if (!((index1 >= 1 && index1 <= size) && (index2 >= 1 && index2 <= size))){
        cout << "Wrong input! Try again.\n";
        return;
    }
    if(index1 == index2) return;
    index1--; index2--;
    if(index1 > index2){
        swap(index1, index2);
    }
    auto start = std::chrono::duration_cast<std::chrono::nanoseconds>(std::chrono::system_clock::now().time_since_epoch()).count();
    List *item1 = listItem(index1);
    List *item2 = listItem(index2);
    if (item1->prev != nullptr) {
        item1->prev->next = item2;
    }else{
        head = item2;
    }
    if (item1->next != item2) {
        item1->next->prev = item2;
    }
    if (item2->prev != item1) {
        item2->prev->next = item1;
    }
    if (item2->next != nullptr) {
        item2->next->prev = item1;
    }
    if(item1->next == item2){
        item2->prev = item1->prev;
        item1->prev = item2;
        item1->next = item2->next;
        item2->next = item1;
        auto end = std::chrono::duration_cast<std::chrono::nanoseconds>(std::chrono::system_clock::now().time_since_epoch()).count();
        cout << "time spent to change elements in list in nanoseconds: " << end - start << "ns\n";
        return;
    }
    List *help = item1->prev;
    item1->prev = item2->prev;
    item2->prev = help;
    help = item1->next;
    item1->next = item2->next;
    item2->next = help;
    auto end = std::chrono::duration_cast<std::chrono::nanoseconds>(std::chrono::system_clock::now().time_since_epoch()).count();
    cout << "time spent to change elements in list in nanoseconds: " << end - start << "ns\n";
}

//получение элемента списка по хначению и индексу. В самой функции пользователь сам определяет как получить элемент
void List::getValueAtList(){
    cout << "What type do you want to get element\n"<<
        "1)by value\n"
        "2)by index\n";
    int type, value, index, count = 0;
    bool flag = false;
    List *cur = head;
    type = checkInput();
    auto start = std::chrono::duration_cast<std::chrono::nanoseconds>(std::chrono::system_clock::now().time_since_epoch()).count();
    switch (type) {
    case 1:
        cout << "Input value:";
        value = checkInput();
        while(cur){
            if(cur->data == value){
                flag = true;
                index = count;
                break;
            }
            cur = cur->next;
            count++;
        }
        if(flag){
            cout << "The list contain an element - " << value << "(index - " << index+1 << ")" << "\n";
        }else{
            cout << "The list does not contain an element - " << value << "\n";
        }
    case 2:
        cout << "Input index:";
        index = checkInput();
        while (!(index >= 1 && index <= size)){
            cout << "Wrong input! Try again.\n";
            index = checkInput();
        }
        cur = listItem(index - 1);
        cout << "Value with index "<< index << " - " << cur->data << "\n";
        break;
    default:
        cout << "Wrong input! Try again.\n";
        getValueAtList();
        break;
    }
    auto end = std::chrono::duration_cast<std::chrono::nanoseconds>(std::chrono::system_clock::now().time_since_epoch()).count();
    cout << "time spent to get element in list in nanoseconds: " << end - start << "ns\n";
}

//удаление элемента по значению и индексу. Как удалять определяет пользователь в самой функции
void List::deleteValueAtList(){
    cout << "What type do you want to delete element\n"<<
        "1)by value\n"
        "2)by index\n";
    int type, value, index, count = 0;
    List *cur = head;
    type = checkInput();
    switch (type) {
    case 1:
        cout << "Input value:";
        value = checkInput();
        break;
    case 2:
        cout << "Input index:";
        index = checkInput();
        while (!(index >= 1 && index <= size)){
            cout << "Wrong input! Try again.\n";
            index = checkInput();
        }
        while(cur){
            if(count == index - 1){
                value = cur->data;
                break;
            }
            cur = cur->next;
            count++;
        }
        break;
    default:
        cout << "Wrong input! Try again.\n";
        deleteValueAtList();
        break;
    }
    count = 0;
    cur = head;
    List *help = nullptr;
    bool flag = false;
    auto start = std::chrono::duration_cast<std::chrono::nanoseconds>(std::chrono::system_clock::now().time_since_epoch()).count();
    while(cur){
        if (cur->data == value){
            flag = true;
            if (cur->prev == nullptr){
                head = cur->next;
                if(cur->next != nullptr)cur->next->prev = nullptr;
                delete cur;
                cur = head;
            }else if(cur->next == nullptr){
                help = cur->next;
                if(cur->prev != nullptr) cur->prev->next = nullptr;
                delete cur;
                cur = help;
            }else{
                help = cur->next;
                cur->prev->next = cur->next;
                cur->next->prev = cur->prev;
                delete cur;
                cur = help;
            }
            count++;
            if(type == 2) break;
        }else{
            cur = cur->next;
        }
    }
    if(!flag){
        cout << "Such element no exist\n";
        return;
    }
    auto end = std::chrono::duration_cast<std::chrono::nanoseconds>(std::chrono::system_clock::now().time_since_epoch()).count();
    cout << "time spent to delete element in list in nanoseconds: " << end - start << "ns\n";
    size -= count;
}

void List::deleteList (){
    List *Next;
    while (head)
    {
        Next = head->next;
        delete head;
        head = Next;
    }
    size--;
}
