#include <iostream>
#include <vector>
#include <memory>

#include "Tarantula.h"
#include "Spider.h"
#include "AutoAttack.h"
#include "Spells.h"
#include "AnimalsRhomb.h"
#include "Processors.h"

using std::cout;
using std::endl;

void ByteWithArachnid(Spider& arachnid)
{
    cout << arachnid.Byte() << endl;
}

int main()
{
    //Tarantula tarantul{};
    //Spider& spider = tarantul;

    //cout << spider.Byte() <<endl;

    //Tarantula tarantul{};
    //Sparassidae sparassidae{};
    //Spider spider{};

    //ByteWithArachnid(tarantul);
    //ByteWithArachnid(sparassidae);
    //ByteWithArachnid(spider);

    //float targetDamage = 13;
    //AcheAutoAttack autoAttack{};

    //autoAttack.Apply(targetDamage);

    //cout << targetDamage << endl;

    //Fireball fireball{};
    //ManaBurn manaburn{};

    //fireball.Use();
    //manaburn.Use();

    //Salamander salamander{};

    
    std::vector<std::shared_ptr<ProcessorBase>> processors{
        std::make_shared<Processor1>(),
        std::make_shared<Processor2>()
    };

    //for (auto& processor : processors)
    //{
    //    auto tempProcessor = dynamic_cast<Processor1*>(processor.get());

    //    if (tempProcessor)
    //    {
    //        tempProcessor->Function1();
    //    }

    //    auto tempProcessor2 = dynamic_cast<Processor2*>(processor.get());

    //    if (tempProcessor)
    //    {
    //        tempProcessor2->Function2();
    //    }
    //}
    

    for (auto& processor : processors)
    {
        auto tempProcessor = static_cast<Processor1*>(processor.get());
        auto tempProcessor2 = static_cast<Processor2*>(processor.get());

        tempProcessor->CommonFunction();
        tempProcessor2->CommonFunction();

        tempProcessor->Function1();
        tempProcessor2->Function2();
    }

    /*Processor1 processor1{};

    ProcessorBase& processorBase = processor1;

    dynamic_cast<Processor1&>(processorBase).Function1();

    try
    {
        dynamic_cast<Processor2&>(processorBase).Function2();
    }
    catch (const std::bad_cast&)
    {
        cout << "wrong convertation" << endl;
    }*/
}

