#include "Serializer.hpp"

#include "Serializer.hpp"

int main(void) {
	Data *data = new Data;

	int nombre = data->number = 10;

	std::cout << "Valeur initiale de Data: " << nombre << std::endl;

	uintptr_t ptr = Serializer::serialize(data);
	Data *ptr2 = Serializer::deserialize(ptr);

	// Comparaison des pointeurs
	if (data == ptr2) {
		std::cout << "La désérialisation a réussi : les pointeurs sont égaux." << std::endl;
	} else {
		std::cout << "La désérialisation a échoué : les pointeurs sont différents." << std::endl;
	}

	delete data;
	return 0;
}
