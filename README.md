# HOMI

**English** | [中文](#中文)

---

## English

HOMI is a lightweight IoT platform for Linux, designed to deliver rich functionality with minimal memory.

### About

HOMI is an IoT solution built for Linux environments with a clear focus on **memory efficiency**.  
We keep RAM usage as low as possible, while intentionally not restricting CPU or storage — so you get the most out of constrained devices.

Our goal is to offer a feature-rich experience comparable to **Home Assistant (HA)**, but running smoothly on embedded boards, old PCs, or any system where every megabyte counts.

### Key Features

- **Memory‑first** – Runtime RAM usage below 128 MB (target < 64 MB)
- **Plugin‑based** – Extend functionality via the community repository `homi_ce`
- **Native Linux** – Works on major distributions, no virtualization needed
- **Fast boot** – From cold start to service ready in seconds
- **Secure & stable** – All plugins are reviewed to ensure system integrity

### How to Contribute

1. **Fork** this repository
2. **Modify** the code – fix bugs, add features, or create plugins
3. **Submit to `homi_ce`** – push your improvements to the community repository
4. **Review** – I will personally review every submission and merge it promptly

#### Plugin Development (brief)

- Write plugins in Python or C (other languages upon request)
- Provide a `manifest.json` describing your plugin
- Implement the standard interface: `init()`, `run()`, `stop()`
- Memory footprint must not exceed 20 MB

### Performance Comparison

| Project          | Min. RAM | Main Language | Use Case                           |
| ---------------- | -------- | ------------- | ---------------------------------- |
| **HOMI**         | < 50 MB  | C / Python    | Resource‑constrained embedded     |
| Home Assistant   | ≥ 1.5 GB | Python        | Full‑featured home servers        |
| Domoticz         | ~ 50 MB  | C++           | Lightweight smart home             |
| openHAB          | ~ 500 MB | Java          | Industrial‑grade integration       |

### Community & Support

- [GitHub Issues](https://github.com/yourusername/homi/issues) – report bugs or suggest features
- [Email](print_114514@outlook.com) – official contact

---

## 中文

HOMI 是一个为 Linux 设计的轻量级 IoT 平台，用最少的内存实现最丰富的功能。

### 项目简介

HOMI 是一个专为 Linux 环境打造的 IoT 解决方案，核心追求是**极致的内存效率**。  
我们严格限制 RAM 占用，同时对 CPU 和硬盘资源保持宽容态度 —— 在你最关心的地方精打细算，在你不介意的地方留出余地。

我们的目标是在资源受限的设备（如嵌入式板卡、老旧主机）上，提供足以媲美 **Home Assistant (HA)** 的功能体验，让每一兆字节都发挥最大价值。

### 主要特性

- **内存优先** – 运行时内存占用低于 128 MB（目标 < 64 MB）
- **插件化** – 通过社区仓库 `homi_ce` 轻松扩展功能
- **原生 Linux** – 支持主流发行版，无需额外虚拟化
- **快速启动** – 从冷启动到服务就绪仅需数秒
- **安全可靠** – 所有插件经过审核，保证系统稳定性

### 如何贡献

1. **复刻（Fork）** 本仓库
2. **修改代码** – 修复 Bug、新增功能或开发插件
3. **提交至 `homi_ce` 社区仓库** – 将你的改进推送至 `homi_ce`
4. **等待审核** – 我会亲自 review 每一个提交，符合要求后立即合并

#### 插件开发规范（简述）

- 使用 Python 或 C 编写（其他语言请提前沟通）
- 提供 `manifest.json` 描述插件信息
- 实现标准接口 `init()`、`run()`、`stop()`
- 内存占用不得超过 20 MB

### 性能对比

| 项目          | 最低内存占用 | 主要语言 | 适用场景               |
| ------------- | ------------ | -------- | ---------------------- |
| **HOMI**      | < 50 MB      | C/Python | 资源受限的嵌入式设备   |
| Home Assistant| ≥ 1.5 GB     | Python   | 功能全面的家庭服务器   |
| Domoticz      | ~ 50 MB      | C++      | 轻量级智能家居         |
| openHAB       | ~ 500 MB     | Java     | 工业级集成             |

### 社区与支持

- [GitHub Issues](https://github.com/yourusername/homi/issues) – 报告 Bug 或提出建议
- [邮件](print_114514@outlook.com) – 官方联系渠道
