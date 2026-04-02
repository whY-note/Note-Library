# Overview of Embodied AI

## 整体流程

```
采集数据
   ↓
训练 policy
   ↓
仿真验证
   ↓
小规模真机测试
   ↓
Benchmark 测试
```



### 训练阶段 Training

数据采集

数据处理

策略训练

### 部署阶段 Deployment



### 评测阶段 Evaluation

仿真评测

真机评测



# 主要模型

当前**具身智能（Embodied AI / Embodied Intelligence）**领域并没有一种统一模型范式，而是逐渐形成了几大技术路线。不同实验室和公司会组合使用 **RL、模仿学习、VLA、多模态大模型、扩散模型等**。下面我按**主流范式逐一列举**并解释它们的作用、优缺点和代表项目。

------

# 1 强化学习（Reinforcement Learning, RL）

Reinforcement Learning

## 核心思想

智能体通过 **trial-and-error 与环境交互**，最大化长期奖励。

典型流程：

```
state -> policy -> action -> environment -> reward -> update policy
```

## 典型算法

- DQN
- PPO
- SAC
- TD3

## 在具身智能中的应用

主要用于：

- 机器人控制
- 运动策略学习
- locomotion（行走、抓取）

## 代表项目

- DeepMind 的机器人控制研究
- OpenAI 的 **OpenAI Rubik’s Cube Robot**

## 优点

- 能学习复杂控制策略
- 不需要人工标注

## 缺点

- 样本效率低
- 现实机器人训练成本高
- sim2real困难

------

# 2 模仿学习（Imitation Learning, IL）

Imitation Learning

## 核心思想

机器人 **模仿人类示范数据**学习策略。

```
human demo → dataset → train policy
```

## 典型方法

- Behavior Cloning (BC)
- DAGGER

## 在具身智能中的应用

例如：

- 机械臂操作
- 抓取
- 工具使用

## 代表系统

- Google DeepMind 的 **RT-1 Robot**
- Tesla 的 **Tesla Optimus**

## 优点

- 训练稳定
- 数据效率高

## 缺点

- 依赖大量人类示范
- 泛化能力弱

------

# 3 VLA（Vision-Language-Action）

Vision-Language-Action Model

这是**目前具身智能最热门方向之一**。

## 核心思想

让机器人同时理解：

```
视觉 + 语言 + 动作
```

模型结构：

```
image + text -> VLA model -> robot action
```

## 代表模型

### Google

- RT-2

### NVIDIA

- GR00T

### Figure

- Figure 01
- 使用 **OpenAI GPT-4**

## 优点

- 具备语言理解能力
- 泛化能力强
- 可迁移到新任务

## 缺点

- 需要大量多模态数据
- 模型巨大

------

# 4 Diffusion Policy（扩散策略）

Diffusion Policy

这是近几年**机器人控制领域非常火的一种模型**。

## 核心思想

使用 **扩散模型生成动作序列**

```
state → diffusion model → action trajectory
```

类似图像生成：

```
noise -> denoise -> action
```

## 代表论文

- Diffusion Policy (Columbia + Stanford)

## 应用

- 机器人抓取
- manipulation
- multi-step control

## 优点

- 可以生成复杂轨迹
- 稳定性比RL高

## 缺点

- 推理速度较慢

------

# 5 世界模型（World Model）

World Model

## 核心思想

学习一个 **环境的可预测模型**

```
state + action -> predicted future state
```

机器人可以：

- 在脑内模拟
- 规划行动

## 代表研究

- Jürgen Schmidhuber 提出的世界模型思想
- DeepMind 的 **Dreamer**

## 优点

- 样本效率高
- 可以做规划

## 缺点

- 模型训练复杂

------

# 6 Transformer Policy

Transformer

许多机器人模型直接使用 **Transformer**。

输入：

```
image tokens
language tokens
state tokens
```

输出：

```
action tokens
```

代表模型：

- RT-1
- RT-2
- PaLM-E

------

# 7 Foundation Model for Robotics

Robotics Foundation Model

类似 **GPT 的机器人版**。

特点：

- 超大规模数据
- 通用机器人技能
- 跨任务泛化

代表模型：

- PaLM-E
- RT-2
- GR00T

------

# 8 分层规划模型（Hierarchical Policy）

Hierarchical Reinforcement Learning

机器人通常会拆成：

```
High-level planner (LLM)
↓
Low-level controller (RL)
```

例如：

```
LLM: “make coffee”
↓
subtasks
- grasp cup
- pour water
- add coffee
```

很多系统：

- LLM做任务规划
- RL做运动控制

------

# 9 LLM Agent + Robotics

LLM Agent

近年来非常流行：

```
LLM -> planning
VLA -> perception
policy -> action
```

代表系统：

- Google **SayCan**
- Microsoft **ChatGPT for Robotics**

------

# 当前主流架构（2024–2026）

具身智能最常见的组合：

```
           LLM
            │
       Task Planning
            │
      VLA / Multimodal
            │
   Policy (RL / Diffusion)
            │
          Robot
```

------

# 当前顶级公司技术路线

### Google DeepMind

- VLA
- Transformer
- 模仿学习

代表模型：

- RT-1
- RT-2

------

### Tesla

- imitation learning
- real world dataset

机器人：

- Tesla Optimus

------

### NVIDIA

- simulation + foundation model

模型：

- GR00T



# 不同模型范式的评测方式

下面整理一份 **2025–2026 主流具身智能 benchmark 中，不同模型范式的评测方式对比**。
 我把它分成 **4类模型**：

- **World Model**
- **VLA（Vision-Language-Action）**
- **Diffusion Policy**
- **RL Policy**

并结合当前常见 benchmark（如 **RoboChallenge、RoboArena、LIBERO、WorldArena** 等）总结其评测指标。

------

# 一、整体对比（核心结论）

| 模型类型             | 典型输出                  | 主要评测目标              | 常见指标                                          | 代表 Benchmark           |
| -------------------- | ------------------------- | ------------------------- | ------------------------------------------------- | ------------------------ |
| **World Model**      | 未来状态 / video / latent | 是否正确建模环境 dynamics | video metrics、prediction error、planning utility | WorldArena、EWMBench     |
| **VLA**              | robot action              | 指令 → 动作执行成功率     | task success rate、generalization                 | RoboChallenge、RoboArena |
| **Diffusion Policy** | action trajectory         | 控制稳定性与轨迹质量      | success rate、trajectory error                    | LIBERO、Bridge、DROID    |
| **RL Policy**        | action                    | reward 最大化             | cumulative reward、sample efficiency              | DMControl、ManiSkill     |

------

# 二、World Model 的评测方式

典型 benchmark：

- WorldArena
- EWMBench

### 评测维度

**1️⃣ Perception fidelity**

评价模型预测环境的能力：

指标：

- PSNR
- SSIM
- LPIPS
- FVD（视频）

这些用于评估 **生成的未来视频或状态是否真实**。

------

**2️⃣ Dynamics prediction**

任务：

```
(st, at) → st+1
```

指标：

- state MSE
- trajectory error
- motion consistency

------

**3️⃣ Functional utility**

即：

> world model 是否真的能帮助 decision making

在 **WorldArena** 中，评测包括：

- world model 作为 **planner**
- world model 作为 **policy evaluator**
- world model 作为 **data generator**

并综合为 **EWMScore**。 

------

# 三、VLA（Vision-Language-Action）评测

典型 benchmark：

- RoboChallenge
- RoboArena

### 1️⃣ Task Success Rate

最核心指标：

```
success rate
```

例如：

```
pick object → success / failure
```

在 **RoboChallenge** 中：

- 共 **30个桌面任务**
- 覆盖 **9类 manipulation**。 

------

### 2️⃣ Instruction following

测试：

```
language instruction → action
```

指标：

- success rate
- instruction accuracy

------

### 3️⃣ Generalization

包括：

- unseen environment
- unseen object
- unseen embodiment

例如：

**RoboArena**
 会在不同环境分布上测试模型泛化能力。 

------

# 四、Diffusion Policy 评测

Diffusion policy 的特点：

```
observation → action trajectory
```

常见 benchmark：

- LIBERO
- Bridge
- DROID
- ManiSkill

------

### 1️⃣ Task Success Rate

仍然是最核心指标：

```
success rate
```

例如：

- open drawer
- pick and place

------

### 2️⃣ Trajectory quality

指标：

- trajectory smoothness
- trajectory error
- collision rate

------

### 3️⃣ Long-horizon performance

例如：

```
10-step manipulation
20-step manipulation
```

常见 benchmark：

- LIBERO-LONG

例如 diffusion + world model 方法在该 benchmark 上可提升任务性能。 

------

# 五、RL Policy 的评测

最经典的评测方式：

```
max reward
```

典型 benchmark：

- DeepMind Control
- ManiSkill
- IsaacGym

------

### 1️⃣ Reward

```
Episode Return
```

例如：

```
walker → reward
cheetah → reward
```

------

### 2️⃣ Sample Efficiency

衡量：

```
需要多少数据达到性能
```

指标：

- steps to threshold
- training sample size

------

### 3️⃣ Robustness

例如：

- noisy observation
- domain randomization

------

# 六、2025具身智能 Benchmark 生态

主要 benchmark 可以按模型类型分类：

| Benchmark     | 评测对象           |
| ------------- | ------------------ |
| WorldArena    | World Model        |
| EWMBench      | World Model        |
| RoboChallenge | VLA                |
| RoboArena     | VLA                |
| LIBERO        | Diffusion / Policy |
| Bridge        | Diffusion / Policy |
| ManiSkill     | RL                 |

------

# 七、一个非常重要的区别（很多论文会混淆）

四种模型的 **评测目标完全不同**：

| 模型             | 评测核心          |
| ---------------- | ----------------- |
| World Model      | **预测环境**      |
| VLA              | **执行任务**      |
| Diffusion Policy | **生成控制轨迹**  |
| RL Policy        | **最大化 reward** |

所以：

```
world model ≠ policy
```

很多论文的错误是：

```
只用 success rate 评 world model
```

但实际上 world model 应该评：

```
prediction + planning utility
```

------

# 八、一个研究者常用的评测体系（推荐）

如果你在研究 **具身模型**，通常用 **三层评测体系**：

```
Level 1  perception
video / state prediction

Level 2  control
action success

Level 3  decision
planning / long-horizon task
```