#pragma once

#include <array>
#include <vector>
#include <iostream>
#include <thread>
#include <algorithm>
#include <stdlib.h>
#include <time.h>

#include "Artillery.h"
#include "Bullet.h"
#include "Enemy.h"

using namespace std;

class Firinglane
{
public:
  Firinglane(int length, int *health) : m_artillery(Artillery(health))
  {
    m_ticks_passed = 0;
    m_length = length;
    m_health = health;
    enemies = {};
    bullets = {};

    srand(time(NULL));
  }

  ~Firinglane()
  {
  }

  string print()
  {
    char *lane = new char[m_length];
    fill_n(lane, m_length, ' ');

    for (Enemy &enemy : enemies)
    {
      if (enemy.getPosition() < m_length)
      {
        lane[enemy.getPosition()] = 'X';
      }
    }

    for (Bullet &bullet : bullets)
    {

      if (bullet.getPosition() < m_length)
      {
        lane[bullet.getPosition()] = '*';
      }
    }

    lane[m_artillery.getPosition()] = '>';

    return string(lane);
  }

  void detectCollision()
  {
    if (bullets.size() > 0 && enemies.size() && bullets.front().getPosition() >= enemies.front().getPosition())
    {
      bullets.erase(bullets.begin());
      enemies.erase(enemies.begin());
    }

    if (enemies.size() && m_artillery.getPosition() >= enemies.front().getPosition())
    {
      enemies.erase(enemies.begin());
      m_artillery.hit();
    }
  }

  void load(int energy)
  {
    m_artillery.load(energy);
  }

  void tick()
  {
    m_ticks_passed++;

    if (rand() % 10000 > max(9900 - m_ticks_passed, 5000))
    {
      enemies.push_back(Enemy(m_length, 1, 1));
    }

    if (enemies.size() > 0)
    {
      Bullet *bullet = m_artillery.shoot();

      if (bullet)
      {
        bullets.push_back(*bullet);
      }
    }

    for (Enemy &enemy : enemies)
    {
      enemy.move();
    }

    detectCollision();

    for (Bullet &bullet : bullets)
    {
      bullet.move();
    }

    if (bullets.size() > 0 && bullets.front().getPosition() > m_length)
    {
      bullets.erase(bullets.begin());
    }

    detectCollision();
  }

  int getPassedTicks()
  {
    return m_ticks_passed;
  }

private:
  int m_ticks_passed;
  int m_length;
  int *m_health;
  Artillery m_artillery;
  vector<Enemy> enemies;
  vector<Bullet> bullets;
};
