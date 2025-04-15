#include <stdio.h>
#include <math.h>

int main()
{
	//0. 변수 선언
	double v0 = 100.0; // 초기 속도 (m/s)
	double theta_deg = 37; // 각도 (도)
	double y0; // 높이
	double g = 9.8; // m/s^2
	double theta_rad; // 라디안
	double PI = 3.141592; // 파이 3.141592
	double t;

	printf("각도를 입력하세요 ==> ");
	scanf_s("%lf", &theta_deg);

	printf("초기속도를 입력하세요 ==> ");
	scanf_s("%lf", &v0);

	printf("초기높이를 입력하세요 ==> ");
	scanf_s("%lf", &y0);

	//1. 
	double v0x;
	double v0y;
    v0x = v0 * cos(theta_deg);
    v0y = v0 * sin(theta_deg);
    double a = -0.5 * g;
    double b = v0x;
    double c = v0y;
    double D = b * b - 4 * a * c;


	theta_rad = theta_deg * PI / 180;


    if (D < 0) {
        printf("오류: 실근이 존재하지 않습니다.\n");
        return 1;
    }

    double t1 = (-b + sqrt(D)) / (2 * a);
    double t2 = (-b - sqrt(D)) / (2 * a);
    double t3 = fmax(t1, t2); // 양수 시간 선택

    printf("(a) 지면에 도달할 때까지의 시간: %.2f 초\n", t3);

    // (b) 수평 거리 계산
    double dh = v0x * t3;
    printf("(b) 수평 거리: %.2f m\n", dh);

    // (c) 속도의 수평 및 수직 성분 계산
    double vx = v0x;
    double vy = v0y - g * t3;
    printf("(c) 속도의 수평 성분: %.2f m/s\n", vx);
    printf("(c) 속도의 수직 성분: %.2f m/s\n", vy);

    // (d) 속도의 크기 계산
    double s = sqrt(vx * vx + vy * vy);
    printf("(d) 속도의 크기: %.2f m/s\n", s);

    // (e) 속도 벡터와 수평 방향이 이루는 각도 계산
    double ang = atan2(vy, vx) * 180.0 / PI;
    printf("(e) 수평 방향과 이루는 각도: %.2f 도\n", ang);

    return 0;



	

}

    