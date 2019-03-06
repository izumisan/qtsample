#ifndef MAINWINDOWVIEWMODEL_H
#define MAINWINDOWVIEWMODEL_H

#include <QObject>
#include <QDebug>
#include "interactionrequest.h"

class MainWindowViewModel : public QObject
{
    Q_OBJECT
    Q_PROPERTY( InteractionRequest* interactionRequest READ interactionRequest CONSTANT )
public:
    MainWindowViewModel( QObject* parent = nullptr )
        : QObject( parent )
        , m_interactionRequest( new InteractionRequest( parent ) )
    {
    }
    virtual ~MainWindowViewModel() = default;

public:
    InteractionRequest* interactionRequest() const { return m_interactionRequest; }
public slots:
    void open()
    {
        auto&& context = std::make_shared<Confirmation>( u8"たいとる", u8"こんてんつ" );
//        m_interactionRequest->raise( context );
//        m_interactionRequest->raise(
//            context,
//            [this](auto&&){ qDebug() << "Accepted"; } );
        m_interactionRequest->raise(
            context,
            [this](auto&& c){ qDebug() << "Accepted" << "result:" << c->resultCode(); },
            [this](auto&& c){ qDebug() << "Rejected" << "result:" << c->resultCode(); } );
    }

private:
    InteractionRequest* m_interactionRequest = nullptr;
};

#endif // MAINWINDOWVIEWMODEL_H
