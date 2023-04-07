# FPF ARPG Template

The FPF ARPG Template is an Action Role-Playing Game (ARPG) project template created with Unreal Engine, featuring essential gameplay systems and components created with AI-assistance. The purpose of this template is to provide a solid foundation for creating ARPGs while showcasing the potential of AI assistance in game development.

## Overview

This project is a result of a collaboration between a developer and an AI assistant, leveraging AI's capabilities to streamline the development process and implement various features more efficiently. The FPF ARPG Template includes:

- A comprehensive inventory system, including item management, equipping, and unequipping functionality
- Character stats and progression, such as experience, leveling, and ability points
- AI-driven non-playable characters (NPCs) using behavior trees
- Procedurally generated levels for infinite replayability
- Customizable abilities and skill trees for unique gameplay experiences

## Naming Conventions

All game-specific classes in the project are prefixed with a "G" (e.g., GInventoryComponent, GCharacterStatsComponent) to differentiate them and maintain a clean and organized codebase.

## Getting Started

To begin using the FPF ARPG Template, clone the repository and open the project in Unreal Engine. From there, you can explore the provided systems and components, as well as customize and expand them to suit your game's requirements.

We hope the FPF ARPG Template serves as an inspiring starting point for your ARPG projects, and that you enjoy discovering the creative and technical possibilities offered by this AI-assisted template.

## Decoupling System and Benefits

The FPF ARPG Template incorporates a powerful decoupling system that significantly enhances the flexibility and maintainability of the project's architecture. By leveraging the `GEventsComponent` and an event bus approach, we can achieve a high degree of modularity and extensibility for the game's features.

### GEventsComponent and Event Bus

The `GEventsComponent` serves as a central hub for handling game events using delegates. It can be attached to any character or object, allowing for efficient communication between different game systems without directly referencing components or creating unnecessary dependencies.

This event-driven approach provides several key benefits:

1. **Modularity**: Game systems and components can be easily added, removed, or modified without affecting the overall architecture, resulting in a more modular and manageable codebase.
2. **Extensibility**: New features can be quickly introduced and seamlessly integrated into the existing game framework, speeding up the development process and reducing the risk of introducing bugs.
3. **Reusability**: Game systems can be easily reused across different projects or shared with the community, fostering collaboration and reducing development time.
4. **Easier Debugging**: The event-driven approach allows for better debugging and troubleshooting, as issues can be traced through the event chain rather than navigating a tangled web of component dependencies.
5. **Scalability**: The decoupling system can handle increasing complexity as the project grows, making it an ideal solution for long-term projects and large-scale games.

### Implementation Example

Here's a simple example of how the `GEventsComponent` can be used to handle events in a decoupled manner:

```cpp
UGEventsComponent* EventsComponent = TargetCharacter->FindComponentByClass<UGEventsComponent>();
if (EventsComponent)
{
	EventsComponent->OnDamageTaken.Broadcast(DamageAmount);
}
```

Functionality can then be bound to the delegate in other components or Blueprints, allowing for an elegant and efficient communication system without the need for direct component references.

By adopting the decoupling system with the GEventsComponent and event bus, the FPF ARPG Template offers a robust and flexible foundation for building complex and feature-rich games that can easily evolve and expand over time.

## AI System

This project utilizes Unreal Engine's built-in **Behavior Tree** system for AI decision-making and planning. The choice to use Behavior Trees offers several advantages:

- Behavior Trees provide a powerful and flexible framework for creating complex AI behaviors.
- They are well-integrated with Unreal Engine, making development more efficient.
- There is a wealth of available resources for learning and implementing Behavior Trees in Unreal Engine.

The decision to use Behavior Trees was made after considering alternative AI planning techniques, such as Goal Oriented Action Planning (GOAP). Ultimately, the integration with Unreal Engine, support resources, and potential for more efficient development made Behavior Trees the preferred choice for this project.

## Contributions

FullPowerFantasy is an open project, and contributions are welcome! If you have any ideas, suggestions, or improvements, please feel free to create an issue or submit a pull request.

## License

This project is licensed under the MIT License. See the LICENSE file for more details.

Please note that this project may include content owned by Epic Games, such as the UE4 Mannequin, animations, or other assets. These assets are provided under the terms of the Unreal Engine EULA and remain the property of Epic Games. The use of these assets is governed by the Unreal Engine EULA, and any redistribution, modification, or commercial use of the Epic Games assets should be done in accordance with the terms of that agreement.

Made with :heart: and AI assistance from OpenAI's ChatGPT.


