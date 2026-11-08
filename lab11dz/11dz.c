#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#include <locale.h>
#include <windows.h>

struct Flight {
    char num[20];
    int vilet;
    int prilet;
    char napr[50];
    char samolet[50];
    double dist;
};
typedef struct Flight F;

int main() {
    setlocale(LC_ALL, "Russian");
    F f[5];

    for (int i = 0; i < 5; i++) {
        int v_h, v_m, p_h, p_m;
        printf("\nВведите рейс %d (номер, часы вылета минуты вылета, часы прилета минуты прилета, направление, самолет, расстояние):\n", i + 1);
        scanf("%s %d %d %d %d %s %s %lf", f[i].num, &v_h, &v_m, &p_h, &p_m, f[i].napr, f[i].samolet, &f[i].dist);

        f[i].vilet = v_h * 60 + v_m;
        f[i].prilet = p_h * 60 + p_m;
    }


    int max_idx = 0;
    double max_speed = 0;
    for (int i = 0; i < 5; i++) {
        int t = f[i].prilet - f[i].vilet;
        if (t <= 0) t += 24 * 60; 

        double speed = f[i].dist / ((double)t / 60.0);
        if (speed > max_speed) {
            max_speed = speed;
            max_idx = i;
        }
    }

    char s1[100], s2[100];
    sprintf(s1, "рейс: %s | направление: %s", f[max_idx].num, f[max_idx].napr);
    sprintf(s2, "самолет: %s | скорость: %.1f км/ч", f[max_idx].samolet, max_speed);

    printf("\n********************************************************************************\n"); 
    printf("*                                                                              *\n"); 
    printf("*                                                                              *\n"); 
    printf("*                                                                              *\n"); 
    printf("* %-76s *\n", s1);                                                                     
    printf("* %-76s *\n", s2);                                                                  
    printf("*                                                                              *\n");
    printf("*                                                                              *\n");
    printf("*                                                                              *\n");
    printf("********************************************************************************\n"); 

    return 0;
}
