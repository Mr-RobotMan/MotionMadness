#include <SFML/Graphics.hpp>
#include <cmath>
#include <iostream>
#ifndef M_PI
#define M_PI 3.14159265358979323846
#endif

struct Ball {
    sf::CircleShape shape;
    sf::Vector2f velocity;
};


float angle_ofdxdy(const sf::Vector2f& dxdy, float& z) {
    float dx = dxdy.x;
    float dy = dxdy.y;

    if (std::abs(dy) < 0.01) {
        dy = 0.01;
    }

    z = std::sqrt(dx * dx + dy * dy);
    float angle = std::atan2(dy, dx); 
    return std::round(angle * 10000) / 10000;
}

std::pair<std::pair<float, float>, std::pair<float, float>> calculateVelocitiesAfterCollision(
    const sf::Vector2f& v1, const sf::Vector2f& v2, const sf::Vector2f& position1, const sf::Vector2f& position2) {
    
    float m1 = 1.0f;
    float m2 = 1.0f;
    sf::Vector2f normal = position2 - position1;
    float normalLength = std::sqrt(normal.x * normal.x + normal.y * normal.y);
    normal /= normalLength;  

    float relativeVelocity = (v2.x - v1.x) * normal.x + (v2.y - v1.y) * normal.y;

    float v1_normal = ((m1 - m2) * relativeVelocity + 2 * m2 * relativeVelocity) / (m1 + m2);
    float v2_normal = ((m2 - m1) * relativeVelocity + 2 * m1 * relativeVelocity) / (m1 + m2);

    sf::Vector2f v1_final = v1 + normal * v1_normal;
    sf::Vector2f v2_final = v2 - normal * v2_normal;

    return {{v1_final.x, v1_final.y}, {v2_final.x, v2_final.y}};
}


void handleCollision(Ball& ball1, Ball& ball2) {
    sf::Vector2f delta = ball2.shape.getPosition() - ball1.shape.getPosition();
    float distance = std::sqrt(delta.x * delta.x + delta.y * delta.y);

    if (distance < ball1.shape.getRadius() + ball2.shape.getRadius()) {
        sf::Vector2f normal = delta / distance;
        // std::cout << "Normal: (" << normal.x << ", " << normal.y << ")\n";
        
        auto impulse = calculateVelocitiesAfterCollision(ball1.velocity, ball2.velocity, ball1.shape.getPosition(), ball2.shape.getPosition());

        ball1.velocity.x = impulse.first.first;
        ball1.velocity.y = impulse.first.second;
        ball2.velocity.x = impulse.second.first;
        ball2.velocity.y = impulse.second.second;

        // std::cout << "Ball1 velocity after collision: (" << ball1.velocity.x << ", " << ball1.velocity.y << ")\n";
        // std::cout << "Ball2 velocity after collision: (" << ball2.velocity.x << ", " << ball2.velocity.y << ")\n";
    }
}
float calculateTotalKineticEnergy(const std::vector<Ball>& balls) {
    float totalEnergy = 0.0f;
    for (const auto& ball : balls) {
        float speed = std::sqrt(ball.velocity.x * ball.velocity.x + ball.velocity.y * ball.velocity.y);
        totalEnergy += 0.5f * speed * speed;
    }
    return totalEnergy;
}

int main() {
    sf::RenderWindow window(sf::VideoMode(1000, 900), "Motion Madness Circular Boundary");
    sf::CircleShape boundary(300);
    boundary.setFillColor(sf::Color::Transparent);
    boundary.setOutlineThickness(3);
    boundary.setOutlineColor(sf::Color::White);
    boundary.setPosition(200, 200); 
    sf::Vector2f boundaryCenter(boundary.getPosition().x + boundary.getRadius(), boundary.getPosition().y + boundary.getRadius());
    float boundaryRadius = boundary.getRadius();

    
    Ball ball1, ball2,ball3, ball4, ball5, ball6;
    ball1.shape.setRadius(15);
    ball1.shape.setFillColor(sf::Color::Red);
    ball1.shape.setPosition(boundaryCenter.x - 50, boundaryCenter.y);
    ball1.velocity = sf::Vector2f(.5f, .5f);

    ball2.shape.setRadius(15);
    ball2.shape.setFillColor(sf::Color::Blue);
    ball2.shape.setPosition(boundaryCenter.x + 50, boundaryCenter.y);
    ball2.velocity = sf::Vector2f(-.5f, -.5f);

    ball3.shape.setRadius(15);
    ball3.shape.setFillColor(sf::Color::Yellow);
    ball3.shape.setPosition(boundaryCenter.x + 50, boundaryCenter.y+50);
    ball3.velocity = sf::Vector2f(-.5f, .5f);

    ball4.shape.setRadius(15);
    ball4.shape.setFillColor(sf::Color::Red);
    ball4.shape.setPosition(boundaryCenter.x , boundaryCenter.y-50);
    ball4.velocity = sf::Vector2f(.5f, .5f);

    ball5.shape.setRadius(15);
    ball5.shape.setFillColor(sf::Color::Blue);
    ball5.shape.setPosition(boundaryCenter.x - 50, boundaryCenter.y);
    ball5.velocity = sf::Vector2f(-2.f, -.5f);

    ball6.shape.setRadius(15);
    ball6.shape.setFillColor(sf::Color::Yellow);
    ball6.shape.setPosition(boundaryCenter.x - 50, boundaryCenter.y-50);
    ball6.velocity = sf::Vector2f(-.5f, .5f);

    std::vector<Ball> balls = {ball1, ball2,ball3,ball4,ball5,ball6};

    while (window.isOpen()) {
        sf::Event event;
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed)
                window.close();
        }

        window.clear();

        window.draw(boundary);

        for (size_t i = 0; i < balls.size(); ++i) {
    auto& ball = balls[i];

    // Move the ball
    ball.shape.move(ball.velocity);

    // Calculate distance to the boundary center
    sf::Vector2f ballCenter = ball.shape.getPosition() + sf::Vector2f(ball.shape.getRadius(), ball.shape.getRadius());
    sf::Vector2f delta = ballCenter - boundaryCenter;
    float distance = std::sqrt(delta.x * delta.x + delta.y * delta.y);

    // Ball-to-boundary collision
    if (distance + ball.shape.getRadius() > boundaryRadius) {
        sf::Vector2f normal = delta / distance;
        ball.velocity = ball.velocity - 2.f * (ball.velocity.x * normal.x + ball.velocity.y * normal.y) * normal;

        // Correct ball position to stay within boundary
        ball.shape.setPosition(
            boundaryCenter.x + (delta.x / distance) * (boundaryRadius - ball.shape.getRadius()) - ball.shape.getRadius(),
            boundaryCenter.y + (delta.y / distance) * (boundaryRadius - ball.shape.getRadius()) - ball.shape.getRadius()
        );
    }

    // Handle collisions with other balls
    for (size_t j = i + 1; j < balls.size(); ++j) {
        handleCollision(balls[i], balls[j]);
    }

    window.draw(ball.shape);
}


        window.display();
    }

    return 0;
}
