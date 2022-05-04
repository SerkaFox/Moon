#include "vigemsdlobject.h"

VigemSDLObject::VigemSDLObject(Vigem::VigemClient * client, QObject *parent):
    QObject(parent)
{
    vigem_client = client;
}

/**
 * @brief Обработать событие клавиатуры
 * @param event Событие клавиатуры
 * @return True, если клиент Vigem обработал событие, иначе False
 */
bool VigemSDLObject::handleKeyboardEvent(SDL_KeyboardEvent *event)
{
    qDebug() << "SDL keyboard event" << event->state << event->keysym.sym;

    if (!vigem_client) {
        return false;
    }
    Qt::Key key = getQtKey(event);

    if (key == Qt::Key_unknown) {
        return false;
    }

    if (vigem_client->isKeyAssociated(key)) {
        if (event->state == SDL_PRESSED) {
            vigem_client->pressKey(key);
        } else if (event->state == SDL_RELEASED) {
            vigem_client->releaseKey(key);
        }
        return true;
    }

    return false;
}

Qt::Key VigemSDLObject::getQtKey(SDL_KeyboardEvent *event)
{
    switch(event->keysym.scancode) {
    case SDL_SCANCODE_0:
        return Qt::Key_0;

    case SDL_SCANCODE_1:
        return Qt::Key_1;

    case SDL_SCANCODE_2:
        return Qt::Key_2;

    case SDL_SCANCODE_3:
        return Qt::Key_3;

    case SDL_SCANCODE_4:
        return Qt::Key_4;

    case SDL_SCANCODE_5:
        return Qt::Key_5;

    case SDL_SCANCODE_6:
        return Qt::Key_6;

    case SDL_SCANCODE_7:
        return Qt::Key_7;

    case SDL_SCANCODE_8:
        return Qt::Key_8;

    case SDL_SCANCODE_9:
        return Qt::Key_9;

    case SDL_SCANCODE_A:
        return Qt::Key_A;

    case SDL_SCANCODE_B:
        return Qt::Key_B;

    case SDL_SCANCODE_C:
        return Qt::Key_C;

    case SDL_SCANCODE_D:
        return Qt::Key_D;

    case SDL_SCANCODE_E:
        return Qt::Key_E;

    case SDL_SCANCODE_F:
        return Qt::Key_F;

    case SDL_SCANCODE_G:
        return Qt::Key_G;

    case SDL_SCANCODE_H:
        return Qt::Key_H;

    case SDL_SCANCODE_I:
        return Qt::Key_I;

    case SDL_SCANCODE_J:
        return Qt::Key_J;

    case SDL_SCANCODE_K:
        return Qt::Key_K;

    case SDL_SCANCODE_L:
        return Qt::Key_L;

    case SDL_SCANCODE_M:
        return Qt::Key_M;

    case SDL_SCANCODE_N:
        return Qt::Key_N;

    case SDL_SCANCODE_O:
        return Qt::Key_O;

    case SDL_SCANCODE_P:
        return Qt::Key_P;

    case SDL_SCANCODE_Q:
        return Qt::Key_Q;

    case SDL_SCANCODE_R:
        return Qt::Key_R;

    case SDL_SCANCODE_S:
        return Qt::Key_S;

    case SDL_SCANCODE_T:
        return Qt::Key_T;

    case SDL_SCANCODE_U:
        return Qt::Key_U;

    case SDL_SCANCODE_V:
        return Qt::Key_V;

    case SDL_SCANCODE_W:
        return Qt::Key_W;

    case SDL_SCANCODE_X:
        return Qt::Key_X;

    case SDL_SCANCODE_Y:
        return Qt::Key_Y;

    case SDL_SCANCODE_Z:
        return Qt::Key_Z;

    default:
        return Qt::Key_unknown;
    }
}
