#include <iostream>
#include <cstring>

using namespace std;

struct Music
{
	string carrier;
	string musicName;
	string artistName;
	double songDuration;
	int count;
	double price;
	Music* next;
};

Music* root = nullptr;

void push(string carrier, string musicName, string artistName, double songDuration, int count, double price)
{
	Music* newNode = new Music;
	
	newNode->carrier = carrier;
	newNode->musicName = musicName;
	newNode->artistName = artistName;
	newNode->songDuration = songDuration;
	newNode->count = count;
	newNode->price = price;

	newNode->next = root;
	root = newNode;
}
double SongDurationByArtist(string artistName)
{
	double total = 0;
	Music* current = root;

	while (current != nullptr)
	{
		if (current->artistName == artistName)
		{
			total += current->songDuration;
		}
		current = current->next;
	}
	return total;
}

double avgCassetePrice()
{
	double sum = 0, avg = 0 , count = 0;

	Music* current = root;

	while (current != nullptr)
	{
		if (current->carrier == "аудіокасета")
		{
			sum += current->price;
			count++;
		}
		current = current->next;
	}
	if (count == 0)
	{
		return 0;
	}
	avg = sum / count;
	cout << "Average cassete price: " << avg << endl;
	return avg;
}

int main()
{
	string artist;
	setlocale(LC_ALL, "ukrainian");

	push("грамплатівка", "song1", "artist1", 3.5, 10, 100);
	push("аудіокасета", "song2", "artist1", 2.3, 4, 80);
	push("лазерний диск", "song3", "artist3", 1.2, 7, 120);
	push("аудіокасета", "song4", "artist4", 3.2, 8, 60);

	cout << "Enter an artist: " << endl;
	cin >> artist;
	cout << "Song duration by artist: " << SongDurationByArtist(artist) << endl;
	avgCassetePrice();



	return 0;
}