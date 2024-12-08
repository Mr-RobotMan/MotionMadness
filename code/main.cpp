// #include <SFML/Graphics.hpp>
// #include <cmath>
// #include <iostream>
// #ifndef M_PI
// #define M_PI 3.14159265358979323846
// #endif

// struct Ball {
//     sf::CircleShape shape;
//     sf::Vector2f velocity;
// };


// float angle_ofdxdy(const sf::Vector2f& dxdy, float& z) {
//     float dx = dxdy.x;
//     float dy = dxdy.y;

//     if (std::abs(dy) < 0.01) {
//         dy = 0.01;
//     }

//     z = std::sqrt(dx * dx + dy * dy);
//     float angle = std::atan2(dy, dx); 
//     return std::round(angle * 10000) / 10000;
// }

// std::pair<std::pair<float, float>, std::pair<float, float>> calculateVelocitiesAfterCollision(
//     const sf::Vector2f& v1, const sf::Vector2f& v2, const sf::Vector2f& position1, const sf::Vector2f& position2) {
    
//     float m1 = 1.0f;
//     float m2 = 1.0f;
//     sf::Vector2f normal = position2 - position1;
//     float normalLength = std::sqrt(normal.x * normal.x + normal.y * normal.y);
//     normal /= normalLength;  

//     float relativeVelocity = (v2.x - v1.x) * normal.x + (v2.y - v1.y) * normal.y;

//     float v1_normal = ((m1 - m2) * relativeVelocity + 2 * m2 * relativeVelocity) / (m1 + m2);
//     float v2_normal = ((m2 - m1) * relativeVelocity + 2 * m1 * relativeVelocity) / (m1 + m2);

//     sf::Vector2f v1_final = v1 + normal * v1_normal;
//     sf::Vector2f v2_final = v2 - normal * v2_normal;

//     return {{v1_final.x, v1_final.y}, {v2_final.x, v2_final.y}};
// }


// void handleCollision(Ball& ball1, Ball& ball2) {
//     sf::Vector2f delta = ball2.shape.getPosition() - ball1.shape.getPosition();
//     float distance = std::sqrt(delta.x * delta.x + delta.y * delta.y);

//     if (distance < ball1.shape.getRadius() + ball2.shape.getRadius()) {
//         sf::Vector2f normal = delta / distance;
//         std::cout << "Normal: (" << normal.x << ", " << normal.y << ")\n";
        
//         auto impulse = calculateVelocitiesAfterCollision(ball1.velocity, ball2.velocity, ball1.shape.getPosition(), ball2.shape.getPosition());

//         ball1.velocity.x = impulse.first.first;
//         ball1.velocity.y = impulse.first.second;
//         ball2.velocity.x = impulse.second.first;
//         ball2.velocity.y = impulse.second.second;

//         std::cout << "Ball1 velocity after collision: (" << ball1.velocity.x << ", " << ball1.velocity.y << ")\n";
//         std::cout << "Ball2 velocity after collision: (" << ball2.velocity.x << ", " << ball2.velocity.y << ")\n";
//     }
// }
// float calculateTotalKineticEnergy(const std::vector<Ball>& balls) {
//     float totalEnergy = 0.0f;
//     for (const auto& ball : balls) {
//         float speed = std::sqrt(ball.velocity.x * ball.velocity.x + ball.velocity.y * ball.velocity.y);
//         totalEnergy += 0.5f * speed * speed;
//     }
//     return totalEnergy;
// }

// int main() {
//     sf::RenderWindow window(sf::VideoMode(1000, 900), "Ball Collision");
//     Ball ball1, ball2,ball3,ball4,ball5,ball6;

//     ball1.shape.setRadius(15);
//     ball1.shape.setFillColor(sf::Color::Red);
//     ball1.shape.setPosition(50, 50);
//     ball1.velocity = sf::Vector2f(.5f, .5f);
//     ball2.shape.setRadius(15);
//     ball2.shape.setFillColor(sf::Color::Blue);
//     ball2.shape.setPosition(100, 50);
//     ball2.velocity = sf::Vector2f(-.5f, -.5f);
//     ball3.shape.setRadius(15);
//     ball3.shape.setFillColor(sf::Color::Yellow);
//     ball3.shape.setPosition(50, 100);
//     ball3.velocity = sf::Vector2f(-.5f, .5f);
//     ball4.shape.setRadius(15);
//     ball4.shape.setFillColor(sf::Color::Red);
//     ball4.shape.setPosition(100, 100);
//     ball4.velocity = sf::Vector2f(.5f, .5f);
//     ball5.shape.setRadius(15);
//     ball5.shape.setFillColor(sf::Color::Blue);
//     ball5.shape.setPosition(100, 150);
//     ball5.velocity = sf::Vector2f(-.5f, -.5f);
//     ball6.shape.setRadius(15);
//     ball6.shape.setFillColor(sf::Color::Yellow);
//     ball6.shape.setPosition(150, 100);
//     ball6.velocity = sf::Vector2f(-.5f, .5f);

//     while (window.isOpen()) {
//         sf::Event event;
//         while (window.pollEvent(event)) {
//             if (event.type == sf::Event::Closed)
//                 window.close();
//         }

//         if (ball1.shape.getPosition().x <= 0 || ball1.shape.getPosition().x + ball1.shape.getRadius() * 2 >= window.getSize().x)
//             ball1.velocity.x = -ball1.velocity.x;

//         if (ball1.shape.getPosition().y <= 0 || ball1.shape.getPosition().y + ball1.shape.getRadius() * 2 >= window.getSize().y)
//             ball1.velocity.y = -ball1.velocity.y;

//         if (ball3.shape.getPosition().x <= 0 || ball3.shape.getPosition().x + ball3.shape.getRadius() * 2 >= window.getSize().x)
//             ball3.velocity.x = -ball3.velocity.x;

//         if (ball3.shape.getPosition().y <= 0 || ball3.shape.getPosition().y + ball3.shape.getRadius() * 2 >= window.getSize().y)
//             ball3.velocity.y = -ball3.velocity.y;

//         if (ball2.shape.getPosition().x <= 0 || ball2.shape.getPosition().x + ball2.shape.getRadius() * 2 >= window.getSize().x)
//             ball2.velocity.x = -ball2.velocity.x;

//         if (ball2.shape.getPosition().y <= 0 || ball2.shape.getPosition().y + ball2.shape.getRadius() * 2 >= window.getSize().y)
//             ball2.velocity.y = -ball2.velocity.y;

//         if (ball4.shape.getPosition().x <= 0 || ball4.shape.getPosition().x + ball4.shape.getRadius() * 2 >= window.getSize().x)
//             ball4.velocity.x = -ball4.velocity.x;

//         if (ball4.shape.getPosition().y <= 0 || ball4.shape.getPosition().y + ball4.shape.getRadius() * 2 >= window.getSize().y)
//             ball4.velocity.y = -ball4.velocity.y;
        
//         if (ball5.shape.getPosition().x <= 0 || ball5.shape.getPosition().x + ball5.shape.getRadius() * 2 >= window.getSize().x)
//             ball5.velocity.x = -ball5.velocity.x;

//         if (ball5.shape.getPosition().y <= 0 || ball5.shape.getPosition().y + ball5.shape.getRadius() * 2 >= window.getSize().y)
//             ball5.velocity.y = -ball5.velocity.y;

//         if (ball6.shape.getPosition().x <= 0 || ball6.shape.getPosition().x + ball6.shape.getRadius() * 2 >= window.getSize().x)
//             ball6.velocity.x = -ball6.velocity.x;

//         if (ball6.shape.getPosition().y <= 0 || ball6.shape.getPosition().y + ball6.shape.getRadius() * 2 >= window.getSize().y)
//             ball6.velocity.y = -ball6.velocity.y;    

//         ball1.shape.move(ball1.velocity);
//         ball2.shape.move(ball2.velocity);
//         ball3.shape.move(ball3.velocity);
//         ball4.shape.move(ball4.velocity);
//         ball5.shape.move(ball5.velocity);
//         ball6.shape.move(ball6.velocity);

//         handleCollision(ball1, ball2);
//         handleCollision(ball1, ball3);
//         handleCollision(ball1, ball4);
//         handleCollision(ball1, ball5);
//         handleCollision(ball1, ball6);
//         handleCollision(ball2, ball3);
//         handleCollision(ball2, ball4);
//         handleCollision(ball2, ball5);
//         handleCollision(ball2, ball6);
//         handleCollision(ball3, ball4);
//         handleCollision(ball3, ball5);
//         handleCollision(ball3, ball6);
//         handleCollision(ball4, ball5);
//         handleCollision(ball4, ball6);
//         handleCollision(ball5, ball6);

//         // std::vector<Ball> balls = {ball1, ball2, ball3, ball4, ball5, ball6};
//         // std::cout << "Total Kinetic Energy: " << calculateTotalKineticEnergy(balls) << std::endl;



//         window.clear();
//         window.draw(ball1.shape);
//         window.draw(ball2.shape);
//         window.draw(ball3.shape);
//         window.draw(ball4.shape);        
//         window.draw(ball5.shape);        
//         window.draw(ball6.shape);        
        
//         window.display();
//     }

//     return 0;
// }
