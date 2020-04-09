#include "SceneItem.h"
#include <QPainter>
SceneItem::SceneItem(QQuickItem *parent) : QQuickPaintedItem(parent)
{
    m_bread = QImage(":/img/bread.png");
    m_trophy = QImage(":/img/trophy.png");
    startTimer(1000 / 60);
}

void SceneItem::paint(QPainter *painter)
{
    painter->save();
    for (const auto &pos : m_trophyPos)
    {
        painter->drawImage(pos, m_trophy);
    }
    for (const auto &pos : m_breadPos)
    {
        painter->drawImage(pos, m_bread);
    }
    painter->restore();
}

void SceneItem::timerEvent(QTimerEvent *e)
{
    Q_UNUSED(e);
    move();
    update();
}
void SceneItem::move()
{
    if (!running())
    {
        return;
    }
    for (auto &breadPos : m_breadPos)
    {
        for (auto &trophyPos : m_trophyPos)
        {
            if (breadPos.intersects(trophyPos))
            {
                m_breadPos.removeOne(breadPos);
                m_trophyPos.removeOne(trophyPos);
                emit getScore();
            }
        }
    }
    for (auto &breadPos : m_breadPos)
    {
        breadPos.adjust(0, -breadSpeed(), 0, -breadSpeed());
        if (breadPos.y() < -m_bread.height())
        {
            m_breadPos.removeOne(breadPos);
        }
    }
    for (auto &trophyPos : m_trophyPos)
    {
        trophyPos.adjust(0, trophySpeed(), 0, trophySpeed());
        if (trophyPos.y() > height())
        {
            emit lose();
        }
    }

    setBreadCount(m_breadPos.size());
    setTrophyCount(m_trophyPos.size());
}

void SceneItem::createBread(int x, int y)
{
    QRect r(x, y - m_bread.height(), m_bread.width(), m_bread.height());
    m_breadPos.append(r);
    setBreadCount(m_breadPos.size());
}

void SceneItem::createTrophy(int x, int y)
{
    if (x + m_trophy.width() > width())
    {
        x = static_cast<int>(width() - m_trophy.width());
    }
    m_trophyPos.append({ x, y, m_trophy.width(), m_trophy.height() });
    setTrophyCount(m_trophyPos.size());
}

void SceneItem::setRunning(bool running)
{
    if (m_running == running)
    {
        return;
    }
    m_running = running;
    if (running)
    {
        m_breadPos.clear();
        m_trophyPos.clear();
        setBreadCount(m_breadPos.size());
        setTrophyCount(m_trophyPos.size());
    }
    emit runningChanged(m_running);
}

void SceneItem::setBreadSpeed(int breadSpeed)
{
    if (m_breadSpeed == breadSpeed)
        return;

    m_breadSpeed = breadSpeed;
    emit breadSpeedChanged(m_breadSpeed);
}

void SceneItem::setTrophySpeed(int trophySpeed)
{
    if (m_trophySpeed == trophySpeed)
    {
        return;
    }
    m_trophySpeed = trophySpeed;
    emit trophySpeedChanged(m_trophySpeed);
}

void SceneItem::setLevel(int level)
{
    if (m_level == level)
    {
        return;
    }
    m_level = level;
    emit levelChanged(m_level);
}

void SceneItem::setScore(int score)
{
    if (m_score == score)
    {
        return;
    }

    m_score = score;
    emit scoreChanged(m_score);
}

void SceneItem::setTrophyCount(int trophyCount)
{
    if (m_trophyCount == trophyCount)
    {
        return;
    }
    m_trophyCount = trophyCount;
    emit trophyCountChanged(m_trophyCount);
}

void SceneItem::setBreadCount(int breadCount)
{
    if (m_breadCount == breadCount)
    {
        return;
    }
    m_breadCount = breadCount;
    emit breadCountChanged(m_breadCount);
}
