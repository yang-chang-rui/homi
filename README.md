<!DOCTYPE html>
<html lang="zh-CN">
<head>
    <meta charset="UTF-8">
    <meta name="viewport" content="width=device-width, initial-scale=1.0">
    <title>HOMI - Lightweight IoT Platform</title>
    <style>
        body {
            font-family: -apple-system, BlinkMacSystemFont, "Segoe UI", Roboto, "Helvetica Neue", Arial, sans-serif;
            max-width: 800px;
            margin: 40px auto;
            padding: 20px;
            line-height: 1.7;
            color: #222;
            background: #fafafa;
        }
        h1 {
            font-size: 2.5rem;
            border-bottom: 3px solid #2c3e50;
            padding-bottom: 6px;
            margin-top: 0;
        }
        h2 {
            margin-top: 2rem;
            border-left: 5px solid #2c3e50;
            padding-left: 12px;
        }
        ul, ol {
            padding-left: 1.5rem;
        }
        li {
            margin: 8px 0;
        }
        .tag {
            display: inline-block;
            background: #2c3e50;
            color: #fff;
            padding: 2px 12px;
            border-radius: 20px;
            font-size: 0.8rem;
            margin-right: 6px;
        }
        hr {
            border: none;
            border-top: 2px dashed #ccc;
            margin: 2rem 0;
        }
        .footer {
            margin-top: 3rem;
            font-size: 0.9rem;
            color: #555;
            border-top: 1px solid #ddd;
            padding-top: 1.5rem;
            text-align: center;
        }
        a {
            color: #1a73e8;
            text-decoration: none;
        }
        a:hover {
            text-decoration: underline;
        }
        table {
            width: 100%;
            border-collapse: collapse;
            background: #fff;
        }
        th, td {
            text-align: left;
            padding: 8px;
        }
        th {
            border-bottom: 2px solid #2c3e50;
        }
        tr {
            border-bottom: 1px solid #eee;
        }
        tr:last-child {
            border-bottom: none;
        }
        .lang-switch {
            text-align: right;
            margin-bottom: 10px;
        }
        .lang-btn {
            background: #2c3e50;
            color: #fff;
            border: none;
            padding: 8px 20px;
            border-radius: 30px;
            font-size: 0.95rem;
            cursor: pointer;
            transition: background 0.2s;
        }
        .lang-btn:hover {
            background: #1a2a3a;
        }
        .lang-btn:focus {
            outline: 2px solid #1a73e8;
        }
    </style>
</head>
<body>

    <div class="lang-switch">
        <button class="lang-btn" id="langToggle">中文</button>
    </div>

    <div id="content"></div>

    <script>
        const enHTML = `
            <h1>HOMI</h1>
            <p style="font-size:1.2rem; color:#2c3e50;">
                A lightweight IoT platform for Linux, designed to deliver rich functionality with minimal memory.
            </p>

            <hr>

            <h2>📖 About</h2>
            <p>
                HOMI is an IoT solution built for Linux environments with a clear focus on <strong>memory efficiency</strong>.
                We keep RAM usage as low as possible, while intentionally not restricting CPU or storage — so you get the most out of constrained devices.
            </p>
            <p>
                Our goal is to offer a feature-rich experience comparable to <strong>Home Assistant (HA)</strong>, but running smoothly on embedded boards, old PCs, or any system where every megabyte counts.
            </p>

            <h2>✨ Key Features</h2>
            <ul>
                <li><span class="tag">Memory‑first</span> Runtime RAM usage below 128 MB (target &lt; 64 MB)</li>
                <li><span class="tag">Plugin‑based</span> Extend functionality via the community repository <code>homi_ce</code></li>
                <li><span class="tag">Native Linux</span> Works on major distributions, no virtualization needed</li>
                <li><span class="tag">Fast boot</span> From cold start to service ready in seconds</li>
                <li><span class="tag">Secure & stable</span> All plugins are reviewed to ensure system integrity</li>
            </ul>

            <h2>🤝 How to Contribute</h2>
            <p>We warmly welcome developers, makers, and IoT enthusiasts to join us!</p>
            <h3>Contribution Steps</h3>
            <ol>
                <li><strong>Fork</strong> this repository</li>
                <li><strong>Modify</strong> the code – fix bugs, add features, or create plugins</li>
                <li><strong>Submit to <code>homi_ce</code></strong> – push your improvements to the community repository</li>
                <li><strong>Review</strong> – I will personally review every submission and merge it promptly if it meets the guidelines</li>
            </ol>

            <h3>Plugin Development (brief)</h3>
            <ul>
                <li>Write plugins in Python or C (other languages may be considered upon request)</li>
                <li>Provide a <code>manifest.json</code> describing your plugin</li>
                <li>Implement the standard interface: <code>init()</code>, <code>run()</code>, <code>stop()</code></li>
                <li>Memory footprint must not exceed 20 MB</li>
            </ul>

            <h2>📊 Performance Comparison (for reference)</h2>
            <table>
                <thead>
                    <tr>
                        <th>Project</th>
                        <th>Min. RAM</th>
                        <th>Main Language</th>
                        <th>Use Case</th>
                    </tr>
                </thead>
                <tbody>
                    <tr>
                        <td><strong>HOMI</strong></td>
                        <td>&lt; 50 MB</td>
                        <td>C / Python</td>
                        <td>Resource‑constrained embedded devices</td>
                    </tr>
                    <tr>
                        <td>Home Assistant</td>
                        <td>≥ 1.5 GB</td>
                        <td>Python</td>
                        <td>Full‑featured home servers</td>
                    </tr>
                    <tr>
                        <td>Domoticz</td>
                        <td>~ 50 MB</td>
                        <td>C++</td>
                        <td>Lightweight smart home</td>
                    </tr>
                    <tr>
                        <td>openHAB</td>
                        <td>~ 500 MB</td>
                        <td>Java</td>
                        <td>Industrial‑grade integration</td>
                    </tr>
                </tbody>
            </table>

            <h2>💬 Community & Support</h2>
            <ul>
                <li><a href="https://github.com/yourusername/homi/issues">GitHub Issues</a> – report bugs or suggest features</li>
                <li><a href="https://discord.gg/your-invite-link">Discord</a> – real‑time chat</li>
                <li><a href="mailto:your@email.com">Email</a> – official contact</li>
            </ul>

            <div class="footer">
                <p>Let's build something great together — for Linux and the love of lean IoT! 🎉</p>
                <p style="font-size:0.8rem; color:#999;">Text‑only introduction · No installation steps · No license restrictions</p>
            </div>
        `;

        const zhHTML = `
            <h1>HOMI</h1>
            <p style="font-size:1.2rem; color:#2c3e50;">
                一个为 Linux 设计的轻量级 IoT 平台，用最少的内存实现最丰富的功能。
            </p>

            <hr>

            <h2>📖 项目简介</h2>
            <p>
                HOMI 是一个专为 Linux 环境打造的 IoT 解决方案，核心追求是<strong>极致的内存效率</strong>。
                我们严格限制 RAM 占用，同时对 CPU 和硬盘资源保持宽容态度 —— 在你最关心的地方精打细算，在你不介意的地方留出余地。
            </p>
            <p>
                我们的目标是在资源受限的设备（如嵌入式板卡、老旧主机）上，提供足以媲美 <strong>Home Assistant (HA)</strong> 的功能体验，让每一兆字节都发挥最大价值。
            </p>

            <h2>✨ 主要特性</h2>
            <ul>
                <li><span class="tag">内存优先</span> 运行时内存占用低于 128 MB（目标 &lt; 64 MB）</li>
                <li><span class="tag">插件化</span> 通过社区仓库 <code>homi_ce</code> 轻松扩展功能</li>
                <li><span class="tag">原生 Linux</span> 支持主流发行版，无需额外虚拟化</li>
                <li><span class="tag">快速启动</span> 从冷启动到服务就绪仅需数秒</li>
                <li><span class="tag">安全可靠</span> 所有插件经过审核，保证系统稳定性</li>
            </ul>

            <h2>🤝 如何贡献</h2>
            <p>我们热忱欢迎每一位开发者、极客和 IoT 爱好者加入！</p>
            <h3>贡献方式</h3>
            <ol>
                <li><strong>复刻（Fork）</strong> 本仓库</li>
                <li><strong>修改代码</strong>：修复 Bug、新增功能或开发插件</li>
                <li><strong>提交至 <code>homi_ce</code> 社区仓库</strong>：将你的改进推送至 <code>homi_ce</code> 仓库</li>
                <li><strong>等待审核</strong>：我会亲自 review 每一个提交，符合要求后立即合并</li>
            </ol>

            <h3>插件开发规范（简述）</h3>
            <ul>
                <li>使用 Python 或 C 编写（其他语言请提前沟通）</li>
                <li>提供 <code>manifest.json</code> 描述插件信息</li>
                <li>实现标准接口 <code>init()</code>、<code>run()</code>、<code>stop()</code></li>
                <li>内存占用不得超过 20 MB</li>
            </ul>

            <h2>📊 性能对比（仅供参考）</h2>
            <table>
                <thead>
                    <tr>
                        <th>项目</th>
                        <th>最低内存占用</th>
                        <th>主要语言</th>
                        <th>适用场景</th>
                    </tr>
                </thead>
                <tbody>
                    <tr>
                        <td><strong>HOMI</strong></td>
                        <td>&lt; 50 MB</td>
                        <td>C / Python</td>
                        <td>资源受限的嵌入式设备</td>
                    </tr>
                    <tr>
                        <td>Home Assistant</td>
                        <td>≥ 1.5 GB</td>
                        <td>Python</td>
                        <td>功能全面的家庭服务器</td>
                    </tr>
                    <tr>
                        <td>Domoticz</td>
                        <td>~ 50 MB</td>
                        <td>C++</td>
                        <td>轻量级智能家居</td>
                    </tr>
                    <tr>
                        <td>openHAB</td>
                        <td>~ 500 MB</td>
                        <td>Java</td>
                        <td>工业级集成</td>
                    </tr>
                </tbody>
            </table>

            <h2>💬 社区与支持</h2>
            <ul>
                <li><a href="https://github.com/yourusername/homi/issues">GitHub Issues</a> – 报告 Bug 或提出建议</li>
                <li><a href="https://discord.gg/your-invite-link">Discord 群组</a> – 实时交流</li>
                <li><a href="mailto:your@email.com">邮件</a> – 官方联系渠道</li>
            </ul>

            <div class="footer">
                <p>让我们一起打造一个属于 Linux 和轻量 IoT 爱好者的优秀项目！🎉</p>
                <p style="font-size:0.8rem; color:#999;">纯文字介绍 · 无安装步骤 · 无许可证限制</p>
            </div>
        `;

        let currentLang = 'en';
        const contentDiv = document.getElementById('content');
        const toggleBtn = document.getElementById('langToggle');

        function render(lang) {
            if (lang === 'en') {
                contentDiv.innerHTML = enHTML;
                toggleBtn.textContent = '中文';
            } else {
                contentDiv.innerHTML = zhHTML;
                toggleBtn.textContent = 'English';
            }
            currentLang = lang;
        }

        toggleBtn.addEventListener('click', function () {
            if (currentLang === 'en') {
                render('zh');
            } else {
                render('en');
            }
        });

        render('en');
    </script>

</body>
</html>
