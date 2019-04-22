#include <iostream>
#include "Person.h"
#include "PersonBuilder.h"
#include "PersonAddressBuilder.h"
#include "PersonJobBuilder.h"

int main()
{
    Person p = Person::create()
            .lives()
                .at("Plaza de Cornella")
                .with_postcode("83017")
                .in("Barcelona")
            .works()
                .at("La Caixa")
                .as("Office Manager")
                .earns(80);

    std::cout << p << std::endl;
    return 0;
};