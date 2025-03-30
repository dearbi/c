import torch
import torch.nn as nn
import torch.optim as optim
from torch.utils.data import DataLoader
from models.lenet5 import LeNet5
from data.dataset import LicensePlateDataset

def train(model, train_loader, criterion, optimizer, device):
    model.train()
    running_loss = 0.0
    
    for images, labels in train_loader:
        images, labels = images.to(device), labels.to(device)
        
        optimizer.zero_grad()
        outputs = model(images)
        loss = criterion(outputs, labels)
        loss.backward()
        optimizer.step()
        
        running_loss += loss.item()
    
    return running_loss / len(train_loader)

def main():
    # 设置设备
    device = torch.device('cuda' if torch.cuda.is_available() else 'cpu')
    
    # 初始化模型
    model = LeNet5().to(device)
    
    # 加载数据集
    train_dataset = LicensePlateDataset('data/train')
    train_loader = DataLoader(train_dataset, batch_size=32, shuffle=True)
    
    # 定义损失函数和优化器
    criterion = nn.CrossEntropyLoss()
    optimizer = optim.Adam(model.parameters(), lr=0.001)
    
    # 训练模型
    num_epochs = 10
    for epoch in range(num_epochs):
        train_loss = train(model, train_loader, criterion, optimizer, device)
        print(f'Epoch [{epoch+1}/{num_epochs}], Loss: {train_loss:.4f}')
    
    # 保存模型
    torch.save(model.state_dict(), 'checkpoints/lenet5_model.pth')

if __name__ == '__main__':
    main() 