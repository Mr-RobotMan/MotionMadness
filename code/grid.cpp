// #include <SFML/Graphics.hpp>
// #include <iostream>
// #include <vector>

// class ChessPiece {
// public:
//     virtual void draw(sf::RenderWindow& window) = 0;
//     virtual bool isValidMove(int startX, int startY, int endX, int endY, bool isFirstMove) = 0;
//     virtual bool isWhite() const = 0;
// };

// class Pawnw : public ChessPiece {
//     sf::CircleShape shape;
// public:
//     Pawnw(float x, float y) {
//         shape.setRadius(20.f);
//         shape.setFillColor(sf::Color::White);
//         shape.setOutlineThickness(1.f);
//         shape.setOutlineColor(sf::Color::Black);
//         shape.setPosition(x + 5.f, y + 5.f);
//     }

//     void draw(sf::RenderWindow& window) override {
//         window.draw(shape);
//     }

//     bool isValidMove(int startX, int startY, int endX, int endY, bool isFirstMove) override {
//         int direction = 1;
//         if (startX == endX && endY == startY + direction * 50) {
//             return true;
//         }
//         if (isFirstMove && startX == endX && endY == startY + direction * 100) {
//             return true;
//         }
//         if (abs(startX - endX) == 50 && endY == startY + direction * 50) {
//             return true;
//         }
//         return false;
//     }

//     bool isWhite() const override {
//         return true;
//     }
// };

// class Pawnb : public ChessPiece {
//     sf::CircleShape shape;
// public:
//     Pawnb(float x, float y) {
//         shape.setRadius(20.f);
//         shape.setFillColor(sf::Color::Black);
//         shape.setOutlineThickness(1.f);
//         shape.setOutlineColor(sf::Color::White);
//         shape.setPosition(x + 5.f, y + 5.f);
//     }

//     void draw(sf::RenderWindow& window) override {
//         window.draw(shape);
//     }

//     bool isValidMove(int startX, int startY, int endX, int endY, bool isFirstMove) override {
//         int direction = -1;
//         if (startX == endX && endY == startY + direction * 50) {
//             return true;
//         }
//         if (isFirstMove && startX == endX && endY == startY + direction * 100) {
//             return true;
//         }
//         if (abs(startX - endX) == 50 && endY == startY + direction * 50) {
//             return true;
//         }
//         return false;
//     }

//     bool isWhite() const override {
//         return false;
//     }
// };
// class ChessBoard {
// public:
//     std::vector<std::vector<ChessPiece*>> board;
//     ChessPiece* selectedPiece;
//     int selectedX, selectedY;

// public:
//     ChessBoard() : selectedPiece(nullptr), selectedX(-1), selectedY(-1) {  // Initialize selectedPiece and coordinates
//         for (int i = 0; i < 8; ++i) {
//             std::vector<ChessPiece*> row;
//             for (int j = 0; j < 8; ++j) {
//                 row.push_back(nullptr);
//             }
//             board.push_back(row);
//         }
//     }

//     void addPiece(int x, int y, ChessPiece* piece) {
//         if (x >= 0 && x < 8 && y >= 0 && y < 8) {
//             board[x][y] = piece;
//         }
//     }

//     void selectPiece(int x, int y) {
//         selectedPiece = board[x][y];
//         selectedX = x;
//         selectedY = y;
//     }

//     void movePiece(int x, int y, bool isFirstMove) {
//         if (selectedPiece != nullptr && selectedPiece->isValidMove(selectedX, selectedY, x, y, isFirstMove)) {
//             board[x][y] = selectedPiece;
//             board[selectedX][selectedY] = nullptr;
//             selectedPiece = nullptr;
//         }
//     }

//     void resetSelection() {
//         selectedPiece = nullptr;
//     }

//     void draw(sf::RenderWindow& window) {
//         for (int i = 0; i < 8; ++i) {
//             for (int j = 0; j < 8; ++j) {
//                 sf::RectangleShape square(sf::Vector2f(50.f, 50.f));
//                 square.setPosition(i * 50.f, j * 50.f);
//                 if ((i + j) % 2 == 0) {
//                     square.setFillColor(sf::Color(245, 245, 220));  // White
//                 } else {
//                     square.setFillColor(sf::Color(0, 0, 0));  // Black
//                 }
//                 window.draw(square);

//                 if (board[i][j] != nullptr) {
//                     board[i][j]->draw(window);
//                 }
//             }
//         }
//     }
// };


// int main() {
//     sf::RenderWindow window(sf::VideoMode(400, 400), "Chess Game");

//     ChessBoard chessboard;
//     chessboard.addPiece(0, 1, new Pawnw(0.f, 50.f));
//     chessboard.addPiece(1, 1, new Pawnw(50.f, 50.f));
//     chessboard.addPiece(2, 1, new Pawnw(100.f, 50.f));
//     chessboard.addPiece(3, 1, new Pawnw(150.f, 50.f));
//     chessboard.addPiece(4, 1, new Pawnw(200.f, 50.f));
//     chessboard.addPiece(5, 1, new Pawnw(250.f, 50.f));
//     chessboard.addPiece(6, 1, new Pawnw(300.f, 50.f));
//     chessboard.addPiece(7, 1, new Pawnw(350.f, 50.f));
//     chessboard.addPiece(0, 6, new Pawnb(0.f, 300.f));
//     chessboard.addPiece(1, 6, new Pawnb(50.f, 300.f));
//     chessboard.addPiece(2, 6, new Pawnb(100.f, 300.f));
//     chessboard.addPiece(3, 6, new Pawnb(150.f, 300.f));
//     chessboard.addPiece(4, 6, new Pawnb(200.f, 300.f));
//     chessboard.addPiece(5, 6, new Pawnb(250.f, 300.f));
//     chessboard.addPiece(6, 6, new Pawnb(300.f, 300.f));
//     chessboard.addPiece(7, 6, new Pawnb(350.f, 300.f));

//     bool isWhiteTurn = true;
//     bool isFirstMove = true;

//     while (window.isOpen()) {
//         sf::Event event;
//         while (window.pollEvent(event)) {
//             if (event.type == sf::Event::Closed) {
//                 window.close();
//             }

//             if (event.type == sf::Event::MouseButtonPressed) {
//                 if (event.mouseButton.button == sf::Mouse::Left) {
//                     int x = event.mouseButton.x / 50;  // Convert to board coordinates
//                     int y = event.mouseButton.y / 50;

                    
//                         // Move the piece
//                         chessboard.movePiece(x, y, isFirstMove);
//                         isFirstMove = false;
//                         chessboard.resetSelection();
                    
//                 }
//             }
//         }

//         window.clear(sf::Color::Black);
//         chessboard.draw(window);
//         window.display();
//     }

//     return 0;
// }

// add, commit, push

// git add .
// git commit -m "initial commit"
// git push origin main
