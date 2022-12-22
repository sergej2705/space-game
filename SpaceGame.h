#pragma once

#include <curses.h>
#include <string>
#include <vector>
#include <iostream>
#include <fstream>

#include "Firinglane.h"
#include "Player.h"

using namespace std;

int width = 10;

class SpaceGame
{
public:
  SpaceGame(int difficulty) : m_player(Player(2, 1))
  {
    m_difficulty = difficulty;

    m_health = 6 - m_difficulty;

    m_length = 50;
    m_width = width;
    m_height = getFiringlaneY(difficulty) - 2;

    m_player.setBound(m_width, m_height);

    m_lanes = {};
    for (int i = 0; i < m_difficulty; i++)
    {
      m_lanes.push_back(Firinglane(m_length, &m_health));
    }

    // ncureses init
    initscr();
    curs_set(0);
    m_gamearea = newwin(m_height + 2, m_width + 2, 0, 0);
    refresh();
    wrefresh(m_gamearea);
    keypad(stdscr, TRUE);
    noecho();
  }

  ~SpaceGame()
  {
    // ncurses clean up
    wclear(m_gamearea);
    endwin();
  }

  void start()
  {
    system("clear");

    print();
    mvaddstr(m_height + 2, 0, string("Move to start").c_str());

    halfdelay(100);

    int input;
    while (((input = getch()) != 'q') && m_health > 0)
    {
      switch (input)
      {
      case KEY_DOWN:
      case 's':
        m_player.moveDown();
        break;
      case KEY_UP:
      case 'w':
        m_player.moveUp();
        break;
      case KEY_LEFT:
      case 'a':
        m_player.moveLeft();
        break;
      case KEY_RIGHT:
      case 'd':
        m_player.moveRight();
        break;
      }

      if (m_player.getPositionX() == 1 && m_player.getPositionY() == 1)
      {
        m_player.loadEnergy(3);
      }

      for (int i = 0; i < m_lanes.size(); i++)
      {
        Firinglane &lane = m_lanes.at(i);
        int y = getFiringlaneY(i);

        if (m_player.getPositionX() == m_width && m_player.getPositionY() == y)
        {
          int energy = m_player.unloadEnergy();
          lane.load(energy);
        }

        lane.tick();
      }

      print();
      halfdelay(3);
    }

    clear();

    int score = m_lanes.at(0).getPassedTicks();
    int highScore = getHighScore();

    if (score > highScore)
    {
      setHighScore(score);
      mvaddstr(1, 0, string("You hit the jackpot and set the new highscore with " + to_string(score) + "!").c_str());
      mvaddstr(3, 0, string("The old highscore was " + to_string(highScore)).c_str());
    }
    else
    {
      mvaddstr(1, 0, string("You scored " + to_string(score) + ", that's not enough to crack the jackpot!").c_str());
      mvaddstr(3, 0, string("The old highscore was " + to_string(highScore)).c_str());
    }
    refresh();

    halfdelay(100);
    input = getch();
    system("clear");
  }

private:
  int getHighScore()
  {
    int score = 0;

    string line;
    ifstream scoreFile("score." + to_string(m_difficulty) + ".sav");
    if (scoreFile.is_open())
    {
      getline(scoreFile, line);
      score = stoi(line);
    }
    scoreFile.close();

    return score;
  }

  void setHighScore(int score)
  {
    ofstream scoreFile("score." + to_string(m_difficulty) + ".sav");
    if (scoreFile.is_open())
    {
      scoreFile << to_string(score);
    }
    scoreFile.close();
  }

  int getFiringlaneY(int i)
  {
    return (i + 1) * 2 - 1;
  }

  void print()
  {
    wclear(m_gamearea);
    clear();
    box(m_gamearea, 0, 0);

    mvwaddch(m_gamearea, 1, 1, 'x');

    for (int i = 0; i < m_lanes.size(); i++)
    {
      Firinglane &lane = m_lanes.at(i);
      int y = getFiringlaneY(i);

      mvwaddch(m_gamearea, y, m_width, 'x');
      mvaddstr(y, m_width + 2, lane.print().c_str());
    }

    for (int i = 1; i <= m_health; i++)
    {
      mvaddch(m_height + 2, i, '.');
    }
    mvaddstr(m_height + 4, 1, string("Score:").c_str());
    mvaddstr(m_height + 5, 1, to_string(m_lanes.at(0).getPassedTicks()).c_str());

    mvwaddch(m_gamearea, m_player.getPositionY(), m_player.getPositionX(), m_player.hasEnergy() ? '0' : 'O');

    refresh();
    wrefresh(m_gamearea);
  }

  Player m_player;

  int m_width;
  int m_height;
  int m_difficulty;
  int m_length;
  int m_health;

  WINDOW *m_gamearea;
  vector<Firinglane> m_lanes;
};
