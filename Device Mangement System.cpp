#include <iostream>
#include <string>
using namespace std;

class Device {
private:
	string brand;
	string model;
	int year;
	string color;
public:
	Device() {
		brand = "";
		model = "";
		year = 0;
		color = "";
	}
	Device(string brand, string model, int year, string color) {
		this->brand = brand;
		this->model = model;
		this->year = year;
		this->color = color;
	}
	void setBrandModel(string brand, string model) {
		this->brand = brand;
		this->model = model;
	}
	void setYearColor(int year, string color) {
		this->year = year;
		this->color = color;
	}

	string getBrand() {
		return brand;
	}
	string getModel() {
		return model;
	}
	int getYear() {
		return year;
	}
	string getColor() {
		return color;
	}
	void displayInfo() {
		cout << "Brand Name: " << getBrand() << endl;
		cout << "Model: " << getModel() << endl;
		cout << "Year: " << getYear() << endl;
		cout << "Color: " << getColor() << endl;
	}
};

class Laptop : public Device {
private:
	double ram_size;
public:
	Laptop() {
		ram_size = 0;
	}
	Laptop(string brand, string model, int year, string color, double ram_size) {
		setBrandModel(brand, model);
		setYearColor(year, color);
		this->ram_size = ram_size;
	}
	void setRam(double ram_size) {
		this->ram_size = ram_size;
	}
	double getRam() {
		return ram_size;
	}
	void DisplayLaptop() {
		Device::displayInfo();
		cout << "RAM Size: " << getRam() << endl;
	}
};
class GamingLaptop: public Laptop {
private:
	string gpu_power;
public:
	GamingLaptop(string brand, string model, int year, string color, double ram_size,string gpu_power){
		Laptop::setBrandModel(brand, model);
		Laptop::setYearColor(year, color);
		Laptop::setRam(ram_size);
		this->gpu_power = gpu_power;
	}
	bool is_high_end() {
		return (gpu_power == "RTX 3080" || gpu_power == "RTX 4090" || gpu_power == "RTX 3070");
	}

	void DisplayGamingLaptop() {
		Laptop::displayInfo();
		cout << "GPU: " << gpu_power << endl;
		cout << "High End: " << (is_high_end() ? "Yes" : "No") << endl;
	}
};

class SmartLaptop: public Laptop {
private:
	double battery_capacity;
public:
	SmartLaptop(string brand, string model, int year, string color, double ram_size, double battery_capacity) {
		Device::setBrandModel(brand, model);
		Device::setYearColor(year, color);
		Laptop::setRam(ram_size);
		this->battery_capacity = battery_capacity;
	}
	bool is_battery_powered() {
		if (battery_capacity > 0) {
			return true;
		}
		else {
			return false;
		}
	}
	void DisplaySmartLaptop() {
		Device::displayInfo();
		cout<<"RAM: "<<Laptop::getRam()<<" GB"<<endl;
		cout << "Battery Capacity: " << battery_capacity << endl;
		cout << "Battery Powered: " << (is_battery_powered() ? "Yes" : "No") << endl;
	}
};

class Tablet : public Device {
private:
	double screen_size;
public:
	Tablet(string brand, string model, int year, string color, double screen_size) {
		Device::setBrandModel(brand, model);
		Device::setYearColor(year, color);
		this->screen_size = screen_size;
	}
	bool is_Large_Screen() {
		return screen_size > 10;
	}

	void DisplayTablet() {
		Device::displayInfo();
		cout << "Screen Size: " << screen_size << endl;
		cout << "Is Large Screen: " << (is_Large_Screen() ? "Yes" : "No") << endl;
	}	
};

class Smartphone: public Device {
private:
	string is_Foldable;
public:
	Smartphone(string brand, string model, int year, string color, string is_Foldable) {
		Device::setBrandModel(brand, model);
		Device::setYearColor(year, color);
		this->is_Foldable = is_Foldable;
	}

bool is_Foldable_phone() {
		return  is_Foldable == "Foldable";
	}

	void DisplaySmartphone() {
		Device::displayInfo();
		cout << "Foldable: " << (is_Foldable_phone() ? "Yes" : "No") << endl;
	}
};

int main() {
	GamingLaptop gl("Alienware", "M15", 2023, "Black", 32, "RTX 3080");
	gl.DisplayGamingLaptop();

	cout << endl;

	SmartLaptop s1("Dell", "XPS 15", 2022, "Silver", 16, 90);
	s1.DisplaySmartLaptop();

	cout << endl;

	Tablet t("Apple", "iPad Pro", 2023, "Space Gray", 12.9);
	t.DisplayTablet();

	cout << endl;

	Smartphone sp("Samsung", "Z Fold 5", 2025, "Mystic Black", "Foldable");
	sp.DisplaySmartphone();

	return 0;

}



