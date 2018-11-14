#ifndef MAINVIEWMODEL_H
#define MAINVIEWMODEL_H

#include <QObject>
#include <QDebug>
#include "relaycommand.h"

namespace viewmodel
{

class MainViewModel : public QObject
{
    Q_OBJECT
    Q_PROPERTY( int value READ value WRITE setValue NOTIFY valueChanged )
    Q_PROPERTY( RelayCommand* fooCommand READ fooCommand CONSTANT )
signals:
    void valueChanged() const;

public:
    MainViewModel( QObject* parent = nullptr )
        : QObject(parent)
        , m_fooCommand()
    {
        m_fooCommand = new RelayCommand(
            parent,
            []{ qDebug() << u8"＼(^o^)／"; },
            [this]() -> bool
            {
                bool ret = false;
                if ( ( m_value % 3 == 0 ) || ( QString("%1").arg(m_value).contains("3") ) )
                {
                    ret = true;
                }
                return ret;
            } );
    }
    virtual ~MainViewModel() = default;

public:
    int value() const
    {
        return m_value;
    }
    void setValue( const int value )
    {
        if ( m_value != value )
        {
            m_value = value;
            emit valueChanged();

            m_fooCommand->raiseCanExecute();
        }
    }
    RelayCommand* fooCommand() const
    {
        return m_fooCommand;
    }

private:
    int m_value = 0;
    RelayCommand* m_fooCommand = nullptr;
};

} // namespace viewmodel

#endif // MAINVIEWMODEL_H
