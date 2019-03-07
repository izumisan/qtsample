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
        qDebug() << __func__;
        static int count = 0;
        auto&& context = std::make_shared<Confirmation>( QString("たいとる %1").arg( ++count ), "こんてんつ" );
        context->setAcceptedAction( [context]{ qDebug() << "Accepted:" << "result:" << context->resultCode(); } );
        context->setRejectedAction( [context]{ qDebug() << "Rejected:" << "result:" << context->resultCode(); } );

        m_interactionRequest->raise( context );
    }

private:
    InteractionRequest* m_interactionRequest = nullptr;
};

#endif // MAINWINDOWVIEWMODEL_H
