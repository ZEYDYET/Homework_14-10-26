#include <stdio.h>
#include <limits.h>
#include <windows.h>

int main () {
    SetConsoleOutputCP(65001);
    SetConsoleCP(65001);

    // У холі факультету встановили автоматичну кавомашину. Її внутрішній
    // лічильник приготовлених порцій кави працює на базі типу unsigned short. Якщо
    // кавомашина зготує більше, лічильник скинеться в 0, і технічна служба втратить
    // гарантійну статистику за рік.

    // Завдання: написати програму, яка зчитує поточне значення лічильника та
    // кількість запланованих порцій на поточний день. Програма повинна:

    // 1. Перевірити за допомогою USHRT_MAX, чи не відбудеться циклічне
    // переповнення.
    // 2. Якщо переповнення не буде – вивести оновлене значення
    // лічильника.
    // 3. Якщо загроза скидання існує — вивести попередження: «УВАГА:
    // лічильник скинеться через N порцій! Потрібне технічне
    // обслуговування!» та обчислити значення, яке покаже лічильник після
    // зациклення.

    unsigned short current_count;
    unsigned int planned_count;

    printf("Введіть поточне значення лічильника: ");
    scanf("%hu", &current_count);

    printf("Введіть заплановане значення кави на день: ");
    scanf("%u", &planned_count);
    
    if (planned_count > (USHRT_MAX - current_count)) {
        unsigned int remained = (USHRT_MAX - current_count) + 1;
        
        unsigned short looped_value = (current_count + planned_count);
        
        printf("Лічильник скинеться через %u порцій! Потрібне технічне обслуговування!", remained);
        printf("Значення, яке покаже лічильник після зациклення: %hu", looped_value); 
    } else {
        unsigned short updated_count = current_count + planned_count;
        printf("Оновлене значення лічильника: %hu", updated_count); 
    }

    return 0;
}