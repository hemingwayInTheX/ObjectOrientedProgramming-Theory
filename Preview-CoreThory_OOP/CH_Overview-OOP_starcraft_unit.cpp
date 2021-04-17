/*���� ���� ������ ���� ��ü ������ �������� �帧 �ľ�*/
#include <iostream>
using namespace std;

class Marine {
public:
	Marine();
	Marine(int x, int y);

	int attack();//������ ����
	void be_attacked(int damage_earn);//�Դ� ������
	void move(int x, int y);//���ο� ��ġ
	void show_status();//���
private:
	int hp;//ü��
	int damage;//���ݷ�
	int coord_x, coord_y;//(x,y)��ġ ��ǥ
	bool is_dead;
};

int main(void) {
	Marine marine1(2, 3);//��ü ���� --> �� ����
	Marine marine2(3, 5);

	marine1.show_status();//���� ���� ���
	marine2.show_status();
	
	cout << endl << "���� 1�� ���� 2�� 11ȸ ����" << endl;
	for (int i = 0; i < 10; i++){
		marine2.be_attacked(marine1.attack());
	}

	marine1.show_status();
	marine2.show_status();
	return 0;
}

Marine::Marine() {//����Ʈ ������
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

void Marine::be_attacked(int damage_earn) {//���� �������� �Ű������� �޾� ���� ü�¿��� ���� ���� ��ŭ ������ ����
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





















