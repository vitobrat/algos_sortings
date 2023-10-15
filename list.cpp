#include "list.h"
#include <iostream>
#include <sstream>
#include <chrono>

using namespace std;

List::List(){

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
}

//создает список из чисел, записанных в строку
void List::createList(string str){
    if (head != nullptr){
        deleteList();
    }
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

//добавляет элемент в список
void List::addValueAtList(int index, int value){
    if (!(index >= 1 && index <= size + 1)){
        cout << "Wrong input! Try again.\n";
        return;
    }
    cout << "Input new value: ";
    List *addItem = new List;
    addItem->data = value;
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
    size++;
}


void List::changeValueAtList(int index1, int index2){
    if (!((index1 >= 1 && index1 <= size) && (index2 >= 1 && index2 <= size))){
        cout << "Wrong input! Try again.\n";
        return;
    }
    if(index1 == index2) return;
    index1--; index2--;
    if(index1 > index2){
        swap(index1, index2);
    }
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
        return;
    }
    List *help = item1->prev;
    item1->prev = item2->prev;
    item2->prev = help;
    help = item1->next;
    item1->next = item2->next;
    item2->next = help;
}

int List::getValueAtListByValue(int value){
    int type, index, count = 0;
    List *cur = head;
    bool flag = false;
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
        return index;
    }
}

//получение элемента списка по хначению и индексу. В самой функции пользователь сам определяет как получить элемент
int List::getValueAtListByIndex(int index){
    int type, value, count = 0;
    bool flag = false;
    List *cur = head; 
    if (index >= 1 && index <= size){
        cur = listItem(index - 1);
        return cur->data;
    }
}

void List::deleteValueAtListByValue(int value){
    int type, count = 0;
    List *cur = head;
    count = 0;
    cur = head;
    List *help = nullptr;
    bool flag = false;
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
        return;
    }
    size -= count;
}

//удаление элемента по значению и индексу. Как удалять определяет пользователь в самой функции
void List::deleteValueAtListByIndex(int index){
    int value, count = 0;
    List *cur = head;
    if (!(index >= 1 && index <= size)){
        return;
    }
    List *help = nullptr;
    bool flag = false;
    while(cur){
        if (count == index){
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
            break;
        }else{
            cur = cur->next;
        }
        count++;
    }
    if(!flag){
        return;
    }
    size -= 1;
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
