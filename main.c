#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

#include "magic.h"


DECL_STRUCT(Point, 3)
FIELD("name", char, 1)
FIELD("x", int, 1)
FIELD("y", int, 1)
END_STRUCT()


DECL_STRUCT(User, 3)
FIELD("id", int, 1)
FIELD("name", char, 256)
FIELD("pass", char, 256)
END_STRUCT()


int main(int argc, char *argv[]) {

    // создаём точку А
    object pointA = Point();
    S(pointA, "name", char) = 'A';  // используем S(объект, поле, тип) чтобы получить (установить) значение поля
    S(pointA, "x", int) = 15;
    S(pointA, "y", int) = 3;

    // создаём точку B
    object pointB = Point();
    S(pointB, "name", char) = 'B';
    S(pointB, "x", int) = 34;
    S(pointB, "y", int) = 156;

    object pointList[2] = {pointA, pointB};  // добавляем наши "объекты" в массив

    for (size_t i = 0; i < 2; i++) {
        object p = pointList[i];
        printf("Point %c:\n", S(p, "name", char));
        printf("\tX-cord: %d\n", S(p, "x", int));
        printf("\tY-cord: %d\n", S(p, "y", int));
    } // дрочим на красивый вывод

    // не забываем очистить память
    del(pointA);
    del(pointB);

    // пример со строками внутри структуры
    object brinza = User();
    S(brinza, "id", int) = 1;
    strcpy(Sp(brinza, "name", char), "brinza");  // используем Sp(объект, поле, тип) чтобы получить указатель на поле, а не значение
    strcpy(Sp(brinza, "pass", char), "123456");

    // печатаем информацию о юзере
    printf("\nUser#%d (name='%s', pass='%s')\n", S(brinza, "id", int), Sp(brinza, "name", char), Sp(brinza, "pass", char));

    del(brinza);

    return 0;
}
