/*게임 유닛 생성을 통한 객체 지향의 전반적인 흐름 파악*/
#include <iostream>
using namespace std;

class Marine {
public:
	Marine();
	Marine(int x, int y);

	int attack();//데미지 리턴
	void be_attacked(int damage_earn);//입는 데미지
	void move(int x, int y);//새로운 위치
	void show_status();//출력
private:
	int hp;//체력
	int damage;//공격력
	int coord_x, coord_y;//(x,y)위치 좌표
	bool is_dead;
};

int main(void) {
	Marine marine1(2, 3);//객체 생성 --> 두 유닛
	Marine marine2(3, 5);

	marine1.show_status();//현재 상태 출력
	marine2.show_status();
	
	cout << endl << "마린 1이 마린 2를 11회 공격" << endl;
	for (int i = 0; i < 10; i++){
		marine2.be_attacked(marine1.attack());
	}

	marine1.show_status();
	marine2.show_status();
	return 0;
}

Marine::Marine() {//디폴트 생성자
	coord_x = coord_y = 0;
	hp : 50;
	damage = 5;
	is_dead = false;
}

Marine::Marine(int x, int y) {
	coord_x = x; coord_y = y;
	hp = 50;
	damage = 5;
	is_dead = false;
}

void Marine::move(int x, int y) {
	coord_x = x; coord_y = y;
}

int Marine::attack() { return damage; }

void Marine::be_attacked(int damage_earn) {//받은 데미지를 매개변수로 받아 기존 체력에서 피해 받은 만큼 에너지 감소
	hp -= damage_earn;
	if (hp <= 0) {
		is_dead = true;
	}
}

void Marine::show_status() {
	cout << "===Marine===" << endl;
	cout << "Location : ( " << coord_x << " , " << coord_y << "  ) " << endl;
	cout << "HP : " << hp << endl;
	cout << "DEAD?";
	if (is_dead == 1) { cout << "yes!\n"; }
	else { cout << "no\n"; }
}





















