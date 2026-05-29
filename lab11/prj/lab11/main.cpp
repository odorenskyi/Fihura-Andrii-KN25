#include "struct_type_project_5.h"

int main()
{
    Node* head = nullptr;

    EducationRegistry university;

    university.edeboCode = 12345;
    university.fullName = "Central Ukrainian National Technical University";
    university.address = "Kropyvnytskyi";
    university.phone = "+380000000000";
    university.email = "mail@university.ua";
    university.foundationYear = 1929;

    addRecord(head, university);

    printRegistry(head);

    return 0;
}
