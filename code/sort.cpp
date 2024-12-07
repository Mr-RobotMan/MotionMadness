// #include <SFML/Graphics.hpp>
// #include <vector>
// #include <algorithm>
// #include <thread>
// #include <chrono>

// const int SCREEN_WIDTH = 800;
// const int SCREEN_HEIGHT = 600;

// const int NUM_ELEMENTS = 150;

// const int DELAY = 100;

// void drawArray(sf::RenderWindow &window, const std::vector<int> &arr, int current =-1, int next =-1) {
//     window.clear(sf::Color::Black);
//     float barWidth = SCREEN_WIDTH / static_cast<float>(arr.size());

//     for (size_t i = 0; i < arr.size(); ++i) {
//         sf::RectangleShape bar;
//         bar.setSize({barWidth - 1, static_cast<float>(arr[i])});
//         bar.setPosition(i * barWidth, SCREEN_HEIGHT - arr[i]);
//         if (static_cast<int>(i)==current || static_cast<int>(i)==next){
//             bar.setFillColor(sf::Color::Red);            
//         }
//         else{
//             bar.setFillColor(sf::Color::White);
//         }
//         window.draw(bar);
//     }

//     window.display();
// }
// using namespace std;

// void quicksort(sf::RenderWindow &window, std::vector<int>& arr, int left, int right) {
//     if (left >= right) return;

//     int pivot = arr[right];
//     int partitionIndex = left;

//     for (int i = left; i < right; i++) {
//         if (arr[i] < pivot) {
//             std::swap(arr[i], arr[partitionIndex]);
//             partitionIndex++;
//         }
//     }
//     std::swap(arr[partitionIndex], arr[right]);
//     drawArray(window, arr, left, right);
//     std::this_thread::sleep_for(std::chrono::milliseconds(DELAY));
//     quicksort(window,arr, left, partitionIndex - 1);
//     quicksort(window, arr, partitionIndex + 1, right);
// }
// // void merge(sf::RenderWindow &window, std::vector<int> &arr, int left, int mid, int right) {
// //     int n1 = mid - left + 1;
// //     int n2 = right - mid;

// //     std::vector<int> L(n1), R(n2);

// //     for (int i = 0; i < n1; ++i)
// //         L[i] = arr[left + i];
// //     for (int i = 0; i < n2; ++i)
// //         R[i] = arr[mid + 1 + i];

// //     int i = 0, j = 0, k = left;
// //     while (i < n1 && j < n2) {
// //         if (L[i] <= R[j]) {
// //             arr[k] = L[i];
// //             i++;
// //         } else {
// //             arr[k] = R[j];
// //             j++;
// //         }
// //         drawArray(window, arr, k);
// //         std::this_thread::sleep_for(std::chrono::milliseconds(DELAY));
// //         k++;
// //     }

// //     while (i < n1) {
// //         arr[k] = L[i];
// //         i++;
// //         drawArray(window, arr, k);
// //         std::this_thread::sleep_for(std::chrono::milliseconds(DELAY));
// //         k++;
// //     }

// //     while (j < n2) {
// //         arr[k] = R[j];
// //         j++;
// //         drawArray(window, arr, k);
// //         std::this_thread::sleep_for(std::chrono::milliseconds(DELAY));
// //         k++;
// //     }
// // }

// // void mergeSort(sf::RenderWindow &window, std::vector<int> &arr, int left, int right) {
// //     if (left < right) {
// //         int mid = left + (right - left) / 2;

// //         mergeSort(window, arr, left, mid);
// //         mergeSort(window, arr, mid + 1, right);

// //         merge(window, arr, left, mid, right);
// //     }
// // }

// int main() {
//     // Initialize SFML window
//     sf::RenderWindow window(sf::VideoMode(SCREEN_WIDTH, SCREEN_HEIGHT), "Sorting Visualizer");

//     // Generate a random array
//     std::vector<int> arr(NUM_ELEMENTS);
//     for (int i = 0; i < NUM_ELEMENTS; ++i) {
//         arr[i] = rand() % SCREEN_HEIGHT;
//     }

//     // Main loop
//     while (window.isOpen()) {
//         sf::Event event;
//         while (window.pollEvent(event)) {
//             if (event.type == sf::Event::Closed) {
//                 window.close();
//             }
//         }

//         drawArray(window, arr);

//         quicksort(window, arr, 0, arr.size()-1);

//         std::this_thread::sleep_for(std::chrono::seconds(1));
//     }

//     return 0;
// }
