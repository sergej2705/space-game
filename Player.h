#pragma once

class Player
{
public:
  Player(int startX, int startY, int boundX, int boundY)
  {
    m_x = startX;
    m_y = startY;
    m_bound_x = boundX;
    m_bound_y = boundY;
    m_energy = 0;
  }

  ~Player()
  {
  }

  int getPositionX()
  {
    return m_x;
  }

  int getPositionY()
  {
    return m_y;
  }

  void loadEnergy(int energy)
  {
    m_energy = energy;
  }

  int unloadEnergy()
  {
    int energy = m_energy;
    m_energy = 0;
    return energy;
  }

  bool hasEnergy()
  {
    return m_energy > 0;
  }

  void moveLeft()
  {
    if (m_x - 1 >= 1)
    {
      m_x--;
    }
  }

  void moveRight()
  {
    if (m_x + 1 <= m_bound_x)
    {
      m_x++;
    }
  }

  void moveUp()
  {
    if (m_y - 1 >= 1)
    {
      m_y--;
    }
  }

  void moveDown()
  {
    if (m_y + 1 <= m_bound_y)
    {
      m_y++;
    }
  }

private:
  int m_x;
  int m_y;
  int m_bound_x;
  int m_bound_y;
  int m_energy;
};
