#include <memory>
#include "surakarta/surakarta_agent/surakarta_agent_base.h"

class SurakartaAgentMine : public SurakartaAgentBase {
   public:
    using SurakartaAgentBase::SurakartaAgentBase;
    SurakartaMove CalculateMove() override;
};